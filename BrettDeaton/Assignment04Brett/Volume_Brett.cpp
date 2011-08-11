#include "Volume_Brett.hpp"
#include "Utils/MyContainers/MyVector.hpp"

double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const double Pi = 3.1415926535897932;
  double result = 0.0;
  for(int i=0;i<radii.Size();++i) {
    double r = radii[i];
    result += (4./3.)*Pi*r*r*r;
  }
  return result;
}
