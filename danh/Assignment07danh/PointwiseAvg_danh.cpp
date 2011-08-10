#include "PointwiseAvg_danh.hpp"
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

  PointwiseAvg_danh::PointwiseAvg_danh(const std::string &Opts,const DataBox&,
                                       const std::string& Dir)
  {
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }

  //--------------------------------------------------------------------------
  void PointwiseAvg_danh::Observe(const DataBox& box, const double /* time */,
                                  const std::string& FirstColumnInDatFiles) const
  {
    // Compute avg
    DataBoxAccess boxA(box,"Observers::PointwiseAvg_danh::Observe");
    const Domain& D = boxA.Get<Domain>("Domain");

    double sum = 0.0;
    int Count = 0;
    for(int sd=0;sd<D.Size();++sd) {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      for(Tensor<DataMesh>::const_iterator i=Input.begin();i!=Input.end();++i) {
        sum += PointwiseAverage(*i);
        ++Count;
      }
    }
    double avg = MPreduceAdd(sum,D.Communicator())/Count;

    // Output the norm   // #8.
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app);
      out << FirstColumnInDatFiles << " " << avg << std::endl;
    }
  }
}

REGISTER_OBSERVER(PointwiseAvg_danh)
