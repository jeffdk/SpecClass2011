#include <iostream>
#include <cstdlib>

#include "StudentProjects/SpecClass2011/jwendell/Assignment04jwendell/Volume_jwendell.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"


int main(int /*arc*/, char** /*argv*/) {
  
  double const PI = 3.1415926535897932;
  const MyVector<double> radii(MV::fill, 3.,4.,5.);
  double AnaVol = (4./3.)*PI*(radii[0]*radii[0]*radii[0] + \
                           radii[1]*radii[1]*radii[1] + \
                           radii[2]*radii[2]*radii[2]);
  double CalcVol = TotalVolumeOfSpheresFromRadii(radii);

  std::cout << "Analytical Volume Sum = " << AnaVol << std::endl;
  std::cout << "Calculated Volume Sum = " << CalcVol << std::endl;
  
  UtilsForTesting u;
  IS_TRUE(CalcVol-AnaVol<1.0e-10,"Error in TotalVolumeOfSpheresFromRadii!! Calculated Volume =/= real volume!! You stupid bitch!!");
             
  return u.NumberOfTestsFailed();
  //return EXIT_SUCCESS;
}
