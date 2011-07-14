#include "Volume_cookgb.hpp"
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const double Pi = 3.1415926535897932;
 
  // sum the cubes of the radii
  double result = 0.0;
  for(int i=0;i<radii.Size();++i) {
    const double r = radii[i];
    result += r*r*r;
  }

  // Convert to total volume and return
  return (4.0/3.0)*Pi*result;
}

