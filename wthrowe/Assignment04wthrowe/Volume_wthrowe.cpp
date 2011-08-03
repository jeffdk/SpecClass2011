#include "Volume_wthrowe.hpp"
#include "Utils/MyContainers/MyVector.hpp"

#include <cmath>

double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const double Pi = M_PI;
  double result = 0.0;
  for(int i=0;i<radii.Size();++i) {
     const double r = radii[i];
     result += (4./3.)*Pi*r*r*r;
  }
  return result;
}
