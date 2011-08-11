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

  PointwiseAvgIlana::PointwiseAvgIlana(const std::string &Opts,
				       const DataBox&,
				       const std::string& Dir) {
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }

  void PointwiseAvgIlana::Observe(const DataBox& box,
		    const double /* TimeForDumpFiles */,
		    const std::string& FirstColumnInDatFiles) const
  {
    DataBoxAccess boxA(box, "Observers::PointwiseAvgIlana::Observe");
    const Domain& D = boxA.Get<Domain>("Domain");

    // find total of points in domain, and number of points
    double sum = 0.0;   
    int numpts = 0;
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);   
      for(Tensor<DataMesh>::const_iterator i=Input.begin();i!=Input.end();++i) {
	for(int j=0;j<(*i).Size();++j)
	  sum += (*i)[j]; // asterisk means a pointer to i
	numpts += (*i).Size();
      }
    }

    sum = MPreduceAdd(sum,D.Communicator()); 
    numpts = MPreduceAdd(numpts,D.Communicator());
 
    // Output the average
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app); 
      out << FirstColumnInDatFiles << " " << sum/numpts << std::endl;
    }
  }
}
 
REGISTER_OBSERVER(PointwiseAvgIlana)
