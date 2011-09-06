//---------------------------------------------------------------------------
// $Id: SphericalHarmonicY.cpp 17922 2011-08-16 21:50:09Z szilagyi $
//
// Computes real-valued spherical harmonics Y_lm(theta,phi)
//
//---------------------------------------------------------------------------
#include "SphericalHarmonicY.hpp"
#include "AssociatedLegendre.hpp"
#include "Factorial.hpp"
#include <cmath>
#include <cstdlib> // This is where 'abs' lives. Stupid,eh?
 
double SphericalHarmonicY(int l, int m,const double theta,const double phi) {
  const int absm = abs(m);
  const double P = sqrt((2*l+1)*Factorial(l-absm)/(4*M_PI*Factorial(l+absm)))
                  *P_lm(l,absm,cos(theta));
  if(m<0)
    return P*sin(absm*phi);
  else
    return P*cos(absm*phi);
}

