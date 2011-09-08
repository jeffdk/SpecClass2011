//---------------------------------------------------------------------------
// $Id: SphericalHarmonicY.cpp 17922 2011-08-16 21:50:09Z szilagyi $
//
// Computes real-valued spherical harmonics Y_lm(theta,phi)
//
//---------------------------------------------------------------------------
#include "SphericalHarmonicYTDM.hpp"

#include "Utils/Math/SphericalHarmonicY.hpp"
#include "Utils/Math/AssociatedLegendre.hpp"
#include "Utils/Math/Factorial.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/DataBox/DataBox.hpp"

#include <cmath>
#include <cstdlib> // This is where 'abs' lives. Stupid,eh?
 
Tensor<DataMesh> SphericalHarmonicYTDM(int l, int m, const Tensor<DataMesh> theta, 
                            const Tensor<DataMesh> phi) {
  REQUIRE(theta.Rank() == phi.Rank(), 
                      "ERROR! theta and phi must be of same rank \n");
  REQUIRE(theta(0).Size() == phi(0).Size(), 
                    "ERROR! theta and phi DataMeshes must be of same size \n");
  const int absm = abs(m);
  const int size = theta(0).Size();
  const IPoint extents(MV::fill, size);
  const Mesh mesh(extents);
  Tensor<DataMesh> result(0, "", mesh); 

  for(int i=0; i<size; i++){
    result(i)[i] = SphericalHarmonicY(l, m, theta(0)[i], phi(0)[i]);
  }
  return(result);
  
}

