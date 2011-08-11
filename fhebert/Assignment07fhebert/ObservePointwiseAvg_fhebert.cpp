#include "ObservePointwiseAvg_fhebert.hpp"
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
  
  PwAvg::PwAvg(const std::string &Opts,const DataBox&,const std::string& Dir)
  {
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }
                  
  void PwAvg::Observe(const DataBox& box,
                      const double,
                      const std::string& FirstColumnInDatFiles) const
  {
    DataBoxAccess boxA(box,"Observers::PwAvg::Observe");
                       const Domain& D = boxA.Get<Domain>("Domain");

    double CumulSum = 0.0;
    int Npoints = 0;

    // calculate the sum and number of points on this processor
    for (int sd=0; sd<D.Size(); ++sd)
    {
      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      
      for (TensorIter iter(Input); iter; ++iter)
        for (int pt=0; pt<Input[iter].Size(); ++pt)
        {
          CumulSum += Input[iter][pt];
          Npoints  += 1;
        }
    }
    
    // combine information on all processors
    const double TotalSum = MPreduceAdd(CumulSum, D.Communicator());
    const int    TotalPts = MPreduceAdd(Npoints,  D.Communicator());

    // calculate average
    const double avg = TotalSum/TotalPts;
    if (D.Communicator().Rank()==0)
    {
      std::ofstream out(mFileName.c_str(), std::ios::app);
      out << FirstColumnInDatFiles << " " << avg << std::endl;
    }
  }
}
REGISTER_OBSERVER(PwAvg)
