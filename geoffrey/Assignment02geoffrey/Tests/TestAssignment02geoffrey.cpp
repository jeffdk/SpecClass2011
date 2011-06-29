#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "Require.hpp"

#include "Assignment02geoffrey.hpp"

int main(int /*argc*/, char** /*argv*/) {

  //Create UtilsForTesting object
  UtilsForTesting u;

  //Try out the new sumVectorsAndThenDivide function

  //First, read in some vectors from the file Vectors.input

  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double divisor = p.Get<double>("Divisor",1.);
  
  //Next, make a vector to store the result

  MyVector<double> result(MV::Size(A.Size()),0.);
  
  //Test that the divisor is nonzero
  IS_TRUE(divisor != 0, "Divisor is zero");

  //REQUIRE the divisor to be nonzero
  //Commented out to verify that the IS_TRUE line above also causes the test 
  //to fail
  //REQUIRE(divisor != 0, "Divisor must be nonzero");

  //Do the computation
  
  result = sumVectorsAndThenDivide(A,B,divisor);

  //Print out the results
  
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "(A+B)/divisor = " << result << std::endl;

  //Test that the result magnitude is zero
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }

  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");

  //How many tests failed?
  std::cout << u.NumberOfTestsFailed() << " tests failed." << std::endl;

  //Return number of failed tests
  return u.NumberOfTestsFailed();
}
