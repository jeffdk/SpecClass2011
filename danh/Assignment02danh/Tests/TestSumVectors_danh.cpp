#include "SumVectors_danh.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"
#include <iostream>
#include <cstdlib>

/// \file
/// Tests library SumVectors_danh
int main(int /*argc*/, char** /*argv*/)
{
  // Read in items from the file Vectors.input
  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  const double divisor     = p.Get<double>("Divisor");

  // Error checking of input
  REQUIRE(A.Size()==B.Size(), "ERROR: Vectors A and B do not have the same size!");
  REQUIRE(divisor != 0.0, "ERROR: Your divisor cannot be zero!");

  // Add the vectors together
  const MyVector<double> result = SumVectors(A,B,divisor);
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Divisor  = " << divisor << std::endl;
  std::cout << "Sum      = " << result << std::endl;

  // Test that the result magnitude is zero given numbers in Vectors.input
  double resultMagnitudeSq = 0.0;
  for(int i=0; i<result.Size(); ++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  IS_ZERO(resultMagnitudeSq, "Ensure sum of vector and its negative nonzero.");

  // This line is confusing because tests should not muddle the effects of
  // checking input files vs. checking libraries. It is unclear exactly what
  // this test is supposed to do.
  IS_TRUE(divisor != 0.0, "Ensure divisor is not zero.");

  return UtilsForTesting::NumberOfTestsFailed();
}
