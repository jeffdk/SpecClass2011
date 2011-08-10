#include "ObservePointwiseAvgwthrowe.hpp"
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
			     const std::string& FirstColumnInDatFiles) const
  {
    const DataBoxAccess boxA(box,"Observers::PointwiseAvg::Observe");
    const Domain& D = boxA.Get<Domain>("Domain");

    double total = 0;
    int npoints = 0;
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      for(Tensor<DataMesh>::const_iterator i=Input.begin();
	  i!=Input.end();
	  ++i) {
	for(int j=0;j<(*i).Size();j++) {
	  total += (*i)[j];
	}
	npoints += (*i).Size();
      }
    }
    total = MPreduceAdd(total, D.Communicator());
    npoints = MPreduceAdd(npoints, D.Communicator());

    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app);
      out << FirstColumnInDatFiles << " " << total/npoints << std::endl;
    }
  }
}

REGISTER_OBSERVER(PointwiseAvg)
