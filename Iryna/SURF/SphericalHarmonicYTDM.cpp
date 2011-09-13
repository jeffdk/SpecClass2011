//---------------------------------------------------------------------------
//
// Computes real-valued spherical harmonics Y_lm(theta,phi) at each point 
// of a Tensor<DataMesh>, given by the <DataMesh>es theta and phi.
//
//---------------------------------------------------------------------------
#include "SphericalHarmonicYTDM.hpp"

#include "Utils/Math/SphericalHarmonicY.hpp"
#include "Utils/Math/AssociatedLegendre.hpp"
#include "Utils/Math/Factorial.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/DataBox/DataBox.hpp"
 
Tensor<DataMesh> SphericalHarmonicYTDM(int l, int m, const DataMesh theta, 
                            const DataMesh phi, const Mesh mesh) {
  REQUIRE(theta.Dim() == phi.Dim(), 
                      "ERROR! theta and phi must be of same rank \n");
  REQUIRE(theta.Size() == phi.Size(), 
                    "ERROR! theta and phi DataMeshes must be of same size \n");

  const int size = theta.Size();
  DataMesh temp(mesh);

  for(int i=0; i<size; i++){
    temp[i] = SphericalHarmonicY(l, m, theta[i], phi[i]);
  }
  Tensor<DataMesh> result(0, "", temp); 
  return(result);
  
}

