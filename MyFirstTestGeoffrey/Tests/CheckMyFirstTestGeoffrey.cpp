#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"

#include "MyFirstTestGeoffrey.hpp"

int main(int /*argc*/, char** /*argv*/) {

  //Try out the new sumVectors function

  //First, read in some vectors from the file Vectors.input

  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  
  //Next, make a vector to store the result
  MyVector<double> result(MV::Size(A.Size()),0.);

  //Add the vectors together
  
  result = sumVectors(A,B);

  //Print out the results
  
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;

  //Test that the result magnitude is zero
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  UtilsForTesting u;
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");

  //Return number of failed tests
  return u.NumberOfTestsFailed();
}
