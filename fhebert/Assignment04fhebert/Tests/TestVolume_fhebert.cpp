#include "StudentProjects/SpecClass2011/fhebert/Assignment04fhebert/Volume_fhebert.hpp"
#include "StudentProjects/SpecClass2011/fhebert/Assignment04fhebert/MyVolume_fhebert.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"
#include <cstdlib>
#include <math.h>

int main(void)
{

  // list of radii
  MyVector<double> radii(MV::fill, 1.1, 2.2, 3.3, 4.4);

  // get total volume from both functions
  double Vtot = TotalVolumeOfSpheresFromRadii(radii);
  double MyVtot = MyTotalVolumeOfSpheresFromRadii(radii);

  // "correct" answer to check against
  const double pi = 3.1415926535897932;
  double Vcorrect = 0.0;
  for (int i=0; i<radii.Size(); ++i)
  {
    Vcorrect += 4.0/3.0 * pi * pow(radii[i],3);
  }

  // check that they're close enough
  const double eps = 1e-10;
  const double magErr = fabs(Vcorrect-Vtot);
  const double magMyErr = fabs(Vcorrect-MyVtot);

  std::cout << "Vcorrect = " << Vcorrect << std::endl;
  std::cout << "Vtot     = " << Vtot << std::endl;
  std::cout << "MyVtot   = " << MyVtot << std::endl;
 
  // check the outputs
  IS_TRUE( magErr < eps,
      "TotalVolumeOfSpheresFromRadii gives wrong value of Vtot");
  IS_TRUE( magMyErr < eps,
      "MyTotalVolumeOfSpheresFromRadii gives wrong value of Vtot");

  return UtilsForTesting::NumberOfTestsFailed();
}


