
#include "ObservePointwiseAvgKeith.hpp"

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
 
  PointwiseAvgKeith::PointwiseAvgKeith(const std::string &Opts, 
                                       const DataBox&, 
                                       const std::string& Dir) 
  {
    OptionParser p(Opts,Help());
    mFileName = PrependDirectory(p.Get<std::string>("Filename"),Dir);
    mInput    = p.Get<std::string>("Input");
  }

  // ================
  void PointwiseAvgKeith
  ::Observe(const DataBox& box,
            const double /* TimeForDumpFiles */,
            const std::string& FirstColumnInDatFiles) const 
  {
    DataBoxAccess boxA(box,"Observers::PointwiseAvgKeith::Observe");
    const Domain& D = boxA.Get<Domain>("Domain");
    
    double sum = 0.;
    int numPoints = 0;

    // sum over subdomains on this proc
    for(int sd=0; sd<D.Size(); ++sd) {

      const int& meshPoints = D[sd].Size();
      numPoints += meshPoints;

      const Tensor<DataMesh>& Input = boxA[sd].Get<Tensor<DataMesh> >(mInput);
      const int numComps = Input.Structure().Size();

      // average over independent components of Input
      for(Tensor<DataMesh>::const_iterator i=Input.begin(); 
          i!=Input.end(); ++i) {
        // sum on mesh point values on each subdomain, divide by num
        // components of Input.  (The later is OK because it
        // commutes with all other summations.)  Increment sum with
        // this value.
        sum += ::PointwiseAverage(*i)*meshPoints/numComps;

      } // end average over components
      
    } // end sum over subdomains on this proc
    //
    // At this point we have: 
    // (sum) The average over components of Input, sum over all mesh points
    // on all subdomains owned by this proc.
    // (numPoints) the sum of the number of mesh points on each
    // Subdomain owned by this proc.

    // ================
    // sum over all procs
    sum       = MPreduceAdd(sum, D.Communicator());
    numPoints = MPreduceAdd(numPoints, D.Communicator());
    //
    // At the point we have the global sum and the global numPoints.

    // Divide to get the average.
    const double avg = sum/numPoints;
 
    // Output
    if(D.Communicator().Rank()==0) {
      std::ofstream out(mFileName.c_str(),std::ios::app);
      out << FirstColumnInDatFiles << " " << avg << std::endl;
    }
  }
}
 
REGISTER_OBSERVER(PointwiseAvgKeith)
