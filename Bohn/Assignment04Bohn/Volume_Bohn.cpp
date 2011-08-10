#include "Volume_Bohn.hpp"
#include "Utils/MyContainers/MyVector.hpp"

#include <cmath>

double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii)
{
  double result = 0.0;
  {
    double r;
    for (int i = 0; i < radii.Size(); i++)
    {
      r = radii[i];
      result += (4./3) * M_PI * r * r * r;
    }
  }
  return result;
}
