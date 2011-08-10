#include "CorrectVolume_Maxim.hpp"

#include <cmath> // for M_PI
#include "Utils/MyContainers/MyVector.hpp"

double CorrectTotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  double result = 0.0; // initializing the summ of the volume of the spheres

  for(int i = 0; i < radii.Size(); ++i) {// looping over the radii
     double r = radii[i]; // auxiliary variable for better readability
     result += (4.0/3.0)*M_PI*r*r*r; // finding the volume of the sphere
  }
  return result;
}
