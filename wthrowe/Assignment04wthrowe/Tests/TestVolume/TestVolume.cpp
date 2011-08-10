#include "StudentProjects/SpecClass2011/wthrowe/Assignment04wthrowe/Volume_wthrowe.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"

#include <cmath>

int main() {
  const MyVector<double> radii(MV::fill, 1, 1.2, 5, 0);
  const double correctAnswer = 170.304 * M_PI;

  const double givenAnswer = TotalVolumeOfSpheresFromRadii(radii);

  IS_EQUAL_EPS(givenAnswer, correctAnswer, "Wrong volume returned (got "
	       << givenAnswer << " instead of " << correctAnswer << ")");

  return UtilsForTesting::NumberOfTestsFailed();
}
