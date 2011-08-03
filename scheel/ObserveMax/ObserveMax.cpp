#include "ObserveMax.hpp"
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

  Max::Max(const std::string &Opts,const DataBox&,const std::string& Dir) { 
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }

  void Max::Observe(const DataBox& box,
		    const double /* TimeForDumpFiles */,
		    const std::string& FirstColumnInDatFiles) const
  {
    // Compute norm
    DataBoxAccess boxA(box,"Observers::Max::Observe");
    const Domain& D = boxA.Get<Domain>("Domain");

    double norm = 0.0;
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      for(Tensor<DataMesh>::const_iterator i=Input.begin();i!=Input.end();++i) {
	const double tmp = ::Max(*i);
	if(tmp>norm) norm = tmp;
      }
    }
    norm = MPreduceMax(norm,D.Communicator());

    // Output the norm
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app);
      out << FirstColumnInDatFiles << " " << norm << std::endl;
    }
  }
}

REGISTER_OBSERVER(Max)
