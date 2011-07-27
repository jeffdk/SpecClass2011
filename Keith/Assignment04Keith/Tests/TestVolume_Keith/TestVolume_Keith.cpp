#include "Volume_KEITH.hpp"
#include "UtilsForTesting.hpp"

#include "MyVector.hpp"

int main() {

  UtilsForTesting u;
  u.SetEps(1.e-8);

  MyVector<double> radii(MV::fill, 1.3, 0.8, 1.15, 1.5);

  IS_EQUAL_EPS(TotalVolumeOfSpheresFromRadii(radii), 31.85522591,
               "Total volume did not agree with correct value.\n");

  return u.NumberOfTestsFailed();
}
  
