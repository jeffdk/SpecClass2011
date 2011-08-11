#include "ObservePointwiseAvghohejd8.hpp"
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
 
  PointwiseAvghohejd8::PointwiseAvghohejd8(const std::string &Opts,const DataBox&,
                const std::string& Dir) {
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }
 
  void PointwiseAvghohejd8::Observe(const DataBox& box,
		    const double /* TimeForDumpFiles */,
		    const std::string& FirstColumnInDatFiles) const
  {
    // Compute average
    DataBoxAccess boxA(box,"Observers::PointwiseAvghohejd8::Observe"); 
    const Domain& D = boxA.Get<Domain>("Domain");      
 
    //work on this processor
    double total = 0.0;
    int counter = 0;   
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);   
      for(Tensor<DataMesh>::const_iterator i=Input.begin();i!=Input.end();++i) { 
        const int size = (*i).Size();
        //average per DataMesh times DataMesh.Size() gives sum of all points 
	total += PointwiseAverage(*i) * size;
        counter += size;  //tracks total size of all DataMeshes
      }
    }

    //combine subdomains on all processors
    total = MPreduceAdd(total,D.Communicator());  //adds DataMesh values across processors
    counter = MPreduceAdd(counter, D.Communicator()); //adds DataMesh sizes across processors
 
    // Output the norm  
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app); 
      out << FirstColumnInDatFiles << " " << total/counter << std::endl;
    }
  }
}
 
REGISTER_OBSERVER(PointwiseAvghohejd8)
