#include "Volume_Maxim.hpp"
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const int Pi = 3.1415926535897932;
  double result = 0.0;
  int i;
  double r;
  for(i=0;i<radii.Size();++i) 
     double r = radii[i];
     result += (4/3)*Pi*r*r*r;
  return result;
}
