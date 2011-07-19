#include "MyVolume_fhebert.hpp"
#include <math.h>
double MyTotalVolumeOfSpheresFromRadii(const MyVector<double>& radii)
{
  //declare pi as a double!
  const double pi = 3.1415926535897932;
  double result = 0.0;

  // don't declare unneeded vars out here
  for (int i=0; i<radii.Size(); ++i)
  {
    // don't even need r in side the loop.. go straight to radii[i]
    result += (4.0/3.0) * pi * pow(radii[i], 3);
  }
  return result;
}
