#include "Volume_KEITH.hpp"
#include "UtilsForTesting.hpp"

#include "MyVector.hpp"

int main() {

  UtilsForTesting u;
  u.SetEps(1.e-8);

  { // 1st test - sample values
    MyVector<double> radii1st(MV::fill, 1.3, 0.8, 1.15, 1.5);
    
    IS_EQUAL_EPS(TotalVolumeOfSpheresFromRadii(radii1st), 31.85522591,
                 "Total volume did not agree with correct value.\n");
  }

  // gotta find out how to test that REQUIRE/ASSERT's are working correctly.
  // I.e. that the code failing represents a successful test.
//   { // 2nd test - errors - zero entries
//     IS_TRUE(!TotalVolumeOfSpheresFromRadii(MyVector<double>(MV::Size(0))),
//             "For radii.Size() = 0, should generate an error.\n");
//   }

//   { // 3rd test - errors - negative radius 
//     MyVector<double> radii3rd(MV::fill, 1.3, 0.8, -0.2, 1.5);
//     IS_TRUE(!TotalVolumeOfSpheresFromRadii(radii3rd),
//             "For negative radius code should generate an error.\n");
//   }


  return u.NumberOfTestsFailed();
}
  
