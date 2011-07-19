#include "MyVector.hpp"
#include "Volume_Ilana.hpp"
#include <math.h>
#define _USE_MATH_DEFINES
#include "Require.hpp"

int main(int /*argc*/, char** /*argv*/) {
 
  // vector of 4 radii
  const MyVector<double> A(MV::fill, 1.0,2.0,3.0,4.0);

  // see what result of Volume_Ilana is
  const double result = TotalVolumeOfSpheresFromRadii(A);
 
  // actual result
  const double correct_result = 100.0*(4.0/3.0)*M_PI;

  // make sure they're the same within rounding errors;
  const double diff = result - correct_result;
  REQUIRE(diff<1e-8 && diff>-1e-8, "Incorrect volume returned!\n correct_result=" 
	  << correct_result << "\n returned result=" << result);
  

  return EXIT_SUCCESS;
}
