#include "StudentProjects/SpecClass2011/Curran/Assignment04Curran/Volume_Curran.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"

/** \file
 * Tests the TotalVolumeOfSpheresFromRadii function.
 */

int main(int /*argc*/, char** /*argv*/) {
    // Set tolerance for testing utils
    UtilsForTesting::SetEps(1.0e-15);

    // Specify four spheres of different radii
    const MyVector<double> radii(MV::fill, 1.0, 2.0, 3.0, 4.0);

    // Check total volume
    const double correct_vol = 4.18879020478639063e2; // Computed using GNU R
    const double vol = TotalVolumeOfSpheresFromRadii(radii);
    IS_EQUAL_EPS(correct_vol, vol, "Total valume of spheres not as expected");

    return UtilsForTesting::NumberOfTestsFailed();
}

