#include "ComputeItemRho.hpp"                                                           
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "SphericalHarmonicYTDM.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include <cstdlib>

namespace ComputeItems {

  using std::string;                                       

  ComputeItemRho::ComputeItemRho(const string& opts):     
    mResult(TensorStructure::Empty) {                     
    OptionParser p(opts, Help());                         
    mOutput=p.Get<string>("Output");
    mInput=p.Get<string>("Input");
    l = p.Get<int>("l");
    m = p.Get<int>("m");
  }
  

  void ComputeItemRho::RecomputeData(const DataBoxAccess& box) const {

     REQUIRE(l >= 0, "ERROR: l must be >= 0");
     REQUIRE(abs(m) <= l, "ERROR: m must be between the values of -l and l");
    
     const Tensor<DataMesh> rho_i=box.Get<Tensor<DataMesh> >(mInput);
  /* REQUIRE(rho_i().Dim == 3, 
              "ERROR: The Dimension of the Tensor<DataMesh> input must be 3");
     REQUIRE(rho_i.Rank == 0,
               "ERROR: The Rank of the Tensor<DataMesh> input must be 0");*/
     const MyVector<DataMesh>& coords=
                           box.Get<MyVector<DataMesh> >("GlobalCoords");
     const Mesh mesh = box.Get<Mesh>("Mesh");

     DataMesh theta(mesh);
     DataMesh phi(mesh); 
    
     theta = acos(coords[2] / sqrt(coords[0]*coords[0] + 
                coords[1]*coords[1] + coords[2]*coords[2]));
     phi = atan(coords[1] / coords[0]);
   
     Tensor<DataMesh> SHY(SphericalHarmonicYTDM(l, m, theta, phi, mesh)); 

     mResult.assign(0, "", rho_i()*SHY());  
  }
}
