#include "ObservePointwiseAvgIryna.hpp"
#include "Utils/DataBox/DataBox.hpp"
#include "Utils/DataBox/DataBoxAccess.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/DataMesh/DataMeshNorms.hpp"
#include "Utils/IO/PrependDirectoryName.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/MiscUtils/MpiUtils.hpp"
#include "Utils/MpiWrappers/MpiCommunicator.hpp"
#include "Dust/Domain/Domain.hpp"
#include <fstream>
#include <string>
 
namespace Observers {
 
  PointwiseAvgIryna::PointwiseAvgIryna(const std::string &Opts,const DataBox&,
                                       const std::string& Dir){ 
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }
 
  void PointwiseAvgIryna::Observe(const DataBox& box,
                   const double /* TimeForDumpFiles */,
                   const std::string& FirstColumnInDatFiles) const
  {
    DataBoxAccess boxA(box,"Observers::Max::Observe"); 
    const Domain& D = boxA.Get<Domain>("Domain");      
 
    double sum_points = 0.0; 
    int num_points = 0;  
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);    
      for(Tensor<DataMesh>::const_iterator i=Input.begin();i!=Input.end();++i){  
        for(int j=0;j<(*i).Size();++j){
          sum_points += (*i)[j];
        }
        num_points += (*i).Size();	  
      }
    }
    sum_points = MPreduceMax(sum_points,D.Communicator());  
    num_points = MPreduceAdd(num_points,D.Communicator());
   
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app); 
      out << FirstColumnInDatFiles << " " << sum_points / num_points << std::endl;
    }
  }
}
 
REGISTER_OBSERVER(PointwiseAvgIryna)
