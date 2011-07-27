#include "TotalVolumeOfSpheresFromRadii_danh.hpp"
#include "UtilsForTesting.hpp"
#include "Assert.hpp"

#include <iostream>
#include <cstdlib>

int main(int /*argc*/, char** /*argv*/) {
    const MyVector<double> Radii(MV::fill, 0.2,1.1,10.,0.);
    std::cout << "TestRadii = " << Radii << std::endl;
    const double RealTotalVolume = 4194.398994870599962145259817026;
    ASSERT(RealTotalVolume > 0, "This value must be >0");
    const double TotalVolume = TotalVolumeOfSpheresFromRadii(Radii);

    UtilsForTesting::SetEps(1.e-14);
    IS_EQUAL_EPS(TotalVolume/RealTotalVolume,1.0,
                 "Volume "<<TotalVolume<<" must match "<<RealTotalVolume);

    return UtilsForTesting::NumberOfTestsFailed();
}
