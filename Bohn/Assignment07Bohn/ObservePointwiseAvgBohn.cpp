#include "ObservePointwiseAvgBohn.hpp"
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

  PointwiseAvg::PointwiseAvg(const std::string &Opts,const DataBox&,const std::string& Dir) {
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

    // avg stores the total until dividing by numPoints
    double avg = 0.0;
    int numPoints = 0;
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      for(Tensor<DataMesh>::const_iterator it = Input.begin();
            it != Input.end(); it++) {
        numPoints += (*it).Size();
        for (int j = 0; j < (*it).Size(); j++)
          avg += (*it)[j];
      }
    }

    avg = MPreduceAdd(avg,D.Communicator());
    numPoints = MPreduceAdd(numPoints,D.Communicator());

    avg /= numPoints;

    // Output the norm
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app);
      out << FirstColumnInDatFiles << " " << avg << std::endl;
    }
  }
}

REGISTER_OBSERVER(PointwiseAvg)
