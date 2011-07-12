//
// francois hebert, jul 2011
//
// tests the implementation of the sumVectors and scaleVector
// library functions
//


#include<iostream>
#include<cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"
#include "Assignment02fhebert.hpp"

// change this flag to switch between available tests
#define USE_REQUIRE 0

// this flag to check that vectors sum to zero
#define CHECK_ZERO_SUM 1


int main(int, char**)
{
  // read in the parameters
  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  const double d = p.Get<double>("DoubleToDivideBy");

  // test legitimacy of input
  if (USE_REQUIRE) {
    // with requires:
    REQUIRE(A.Size() == B.Size(), "Error: Vectors not the same size");
    REQUIRE(d != 0.0, "Error: Trying to divide by zero!");
  } else {
    // with utils:
    IS_EQUAL(A.Size(), B.Size(), "Vectors not the same size");
    IS_TRUE(d != 0.0, "Trying to divide by zero");
  }

  // division by d is multiplication by 1/d
  const double scaleFactor = 1.0/d;
  const MyVector<double> sum    = sumVectors(A, B);
  const MyVector<double> result = scaleVector(sum, scaleFactor);

  // check sum=0 if wanted
  if (CHECK_ZERO_SUM) {
    double MagSq = 0.0;
    for (int i=0; i<sum.Size(); ++i) {
      MagSq += sum[i]*sum[i];
    }
    IS_ZERO(MagSq, "Sum of two vectors nonzero");
  }

  std::cout << "Vector A    = " << A << std::endl;
  std::cout << "Vector B    = " << B << std::endl;
  std::cout << "Denominator = " << d << std::endl;
  std::cout << "Result      = " << result << std::endl;

  if (USE_REQUIRE) {
    return EXIT_SUCCESS;
  } else {
    return UtilsForTesting::NumberOfTestsFailed();
  }
}
