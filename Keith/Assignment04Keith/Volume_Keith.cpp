#include "Volume_Keith.hpp" 
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/Require.hpp"

double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
  // I'm using REQUIRE's because I don't have debug turned on.  But these
  // should probably be ASSERT's.
  REQUIRE(radii.Size() > 0, 
          "radii argument must have non-zero Size.\n");
  for(int i=0; i<radii.Size(); ++i)
    REQUIRE(radii[i] >= 0.,
            "radii[" << i << "] must be non-negative, not " << radii[i]
            << ".\n");

  const double Pi = 3.1415926535897932; 
  double result = 0.0; 
  for(int i=0; i<radii.Size(); ++i) {
    const double& r = radii[i];
    result += (4./3.)*Pi*r*r*r; 
  }
  return result;
}
