#include "ObservePointwiseAvg.hpp"
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
 
  PointwiseAvg::PointwiseAvg(const std::string &Opts, const DataBox&, 
							 const std::string& Dir) {
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }
 
  void PointwiseAvg::Observe(const DataBox& box,
		    				 const double /* TimeForDumpFiles */,
		    				 const std::string& FirstColumnInDatFiles) const {
    // Compute norm
    DataBoxAccess boxA(box,"Observers::PointwiseAvg::Observe");
    const Domain& D = boxA.Get<Domain>("Domain");
 
    double average = 0.0;   
    for(int sd=0;sd<D.Size();++sd) {
	  double sum = 0.0;
	  int count = 0;
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      
	  for(Tensor<DataMesh>::const_iterator i=Input.begin();
		  i!=Input.end() ; ++i) {  // #5.
		const double tmp = ::PointwiseAverage(*i);   // #6.
		sum += tmp;
		++count;
      }
	  average = sum/count;
    }
    average = MPreduceMax(average,D.Communicator());  // #7.
 
    // Output the norm   // #8.
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app); // #9.
      out << FirstColumnInDatFiles << " " << average << std::endl;
    }
  }
}
 
REGISTER_OBSERVER(PointwiseAvg)
