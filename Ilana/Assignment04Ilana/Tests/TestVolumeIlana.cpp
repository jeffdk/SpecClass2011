#include "MyVector.hpp"
#include "Volume_Ilana.hpp"
#include <math.h>
#define _USE_MATH_DEFINES
#include "UtilsForTesting.hpp"

int main(int /*argc*/, char** /*argv*/) {

  // Tolerance for testing
  UtilsForTesting::SetEps(1.0e-10);
 
  // vector of 4 radii
  const MyVector<double> A(MV::fill, 1.0,2.0,3.0,4.0);

  // see what result of Volume_Ilana is
  const double result = TotalVolumeOfSpheresFromRadii(A);
 
  // actual result
  const double correct_result = 100.0*(4.0/3.0)*M_PI;

  // make sure they're the same within rounding errors;
  IS_EQUAL_EPS(result,correct_result, "Incorrect volume returned!\n correct_result="  << correct_result << "\n returned result=" << result);
  

  return UtilsForTesting::NumberOfTestsFailed();
}
