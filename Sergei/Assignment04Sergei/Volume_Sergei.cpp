#include "Volume_Sergei.hpp"
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const double Pi = 3.1415926535897932;
  double result = 0.0;
  double r=0.0;
  for(int i=0;i<radii.Size();i++){ 
     r = radii[i];
     result += (4./3)*Pi*r*r*r;
  }
  return result;
}
