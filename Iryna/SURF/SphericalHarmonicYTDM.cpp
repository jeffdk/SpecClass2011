//---------------------------------------------------------------------------
// $Id: SphericalHarmonicY.cpp 17922 2011-08-16 21:50:09Z szilagyi $
//
// Computes real-valued spherical harmonics Y_lm(theta,phi)
//
//---------------------------------------------------------------------------
#include "SphericalHarmonicYTDM.hpp"
#include "Utils/Math/AssociatedLegendre.hpp"
#include "Utils/Math/Factorial.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/DataBox/DataBox.hpp"

#include <cmath>
#include <cstdlib> // This is where 'abs' lives. Stupid,eh?
 
Tensor<DataMesh> SphericalHarmonicY(int l, int m, const DataBoxAccess& box, 
                   const Tensor<DataMesh> theta, const Tensor<DataMesh> phi) {
  REQUIRE(theta.Rank() == phi.Rank(), 
                      "ERROR! theta and phi must be of same rank \n");
  const int absm = abs(m);
  const Mesh mesh = box.Get<Mesh>("Mesh");
  const Tensor<DataMesh> P(0, "", mesh); 
  const Tensor<DataMesh> result(0, "", mesh);
  
  P(0) = sqrt((2*l+1)*Factorial(l-absm)/(4*M_PI*Factorial(l+absm)))
                  *P_lm(l,absm,cos(theta(0)));
  if(m<0){
    result(0) = P*sin(absm*phi(0));
    return result;
  }
  else
    result(0) = P*cos(absm*phi(0));
    return result;
}

