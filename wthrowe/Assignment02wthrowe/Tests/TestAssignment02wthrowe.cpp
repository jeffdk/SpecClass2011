#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"
#include "Assignment02wthrowe.hpp"

int main(int /*argc*/, char** /*argv*/) {

  //Try out the new sumVectors function

  //First, read in some vectors from the file Vectors.input

  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  const double d = p.Get<double>("Divisor");

  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size.");
  REQUIRE(d != 0, "Divisor must be nonzero");
  //IS_TRUE(d != 0, "Divisor is zero");

  //Next, make a vector to store the result

  const MyVector<double> result = sumVectors(A, B, d);

  //Test that the result magnitude is zero
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero...bug?");

  //Print out the results

  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;

  return UtilsForTesting::NumberOfTestsFailed();
}
