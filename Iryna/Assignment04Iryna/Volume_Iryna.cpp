#include "Volume_Iryna.hpp"
// Compute total volume of spheres from given radii
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  const double Pi = 3.1415926535897932;
  double totalVolume = 0.0;
  for(int i=0;i<radii.Size();i++) 
     totalVolume += (4.0/3.0)*Pi*radii[i]*radii[i]*radii[i];
  return totalVolume;
}

