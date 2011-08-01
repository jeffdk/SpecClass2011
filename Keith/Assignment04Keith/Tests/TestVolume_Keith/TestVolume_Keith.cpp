#include "StudentProjects/SpecClass2011/Keith/Assignment04Keith/Volume_Keith.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"

#include "Utils/MyContainers/MyVector.hpp"

int main() {

  // UtilsForTesting u;
  // Ah, I see.  UtilsForTesting member functions are static, so we don't
  // need to instantiate the class.
  UtilsForTesting::SetEps(1.e-8);

  { // 1st test - sample values
    std::cout << "Test 1: epsilon test of output" << std::endl;
    MyVector<double> radii1st(MV::fill, 1.3, 0.8, 1.15, 1.5);
    
    IS_EQUAL_EPS(TotalVolumeOfSpheresFromRadii(radii1st), 31.85522591,
                 "Test 1: Total volume did not agree with correct value.\n");
  }

  // ================================================================
  // I've added the following two tests for fun.  I wanted to see if I
  // could construct tests that pass when the code errors out.  I'm
  // thinking these might be useful for testing how well some code
  // deals with unreasonable input data.
  //
  // based on Utils/Tests/TestExceptionHandling
  // but I've added UtilsForTesting macros to keep track of how many 
  // tests failed.

  { // 2nd test - test REQUIRE/ASSERTs - zero size MyVector
    std::cout << "Test 2: testing REQUIRE(radii.Size > 0)" << std::endl;
    bool testPassed = false;
    try { 
      TotalVolumeOfSpheresFromRadii(MyVector<double>(MV::Size(0)));
      
    } catch (const CodeError& ce) {
      std::cout << "Caught the error..." << std::endl;
      testPassed = true;
    }
    IS_TRUE(testPassed, "Test 2: failed to generate an error.");
  }

  { // 3rd test - test REQUIRE/ASSERTs - negative radius
    std::cout << "Test 3: testing REQUIRE(radius > 0)" << std::endl;
    bool testPassed = false;
    try { 
      TotalVolumeOfSpheresFromRadii
        (MyVector<double>(MV::fill, 1.3, 0.8, -0.2, 1.5));
      
    } catch (const CodeError& ce) {
      std::cout << "Caught the error..." << std::endl;
      testPassed = true;
    }
    IS_TRUE(testPassed, "Test 3: failed to generate an error.");
  }

  return UtilsForTesting::NumberOfTestsFailed();
}
  
