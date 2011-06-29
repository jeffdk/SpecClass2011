#include <iostream>
#include <cstdlib>
 
#include "MyVector.hpp"
#include "Assignment02jeffdk.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "Require.hpp"

int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                         
 
  //First, read in some vectors from the file Vectors.input                     
 
  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double divisor     = p.Get<double>("Divisor");

  //Next, make a vector to store the result                                     
 
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Add the vectors together                                                    
 
  result = sumVectorsThenDivide(A,B,divisor);
  //result = A;           //This line is a forced break of the test
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum / divsor  = " << result << std::endl;

  //Test that the result magnitude is zero                                      
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }

  //A REQUIRE could be used too, instead of UtilsForTesting
  //REQUIRE(resultMagnitudeSq == 0.0,"Sum of vector and its negative nonzero.");
  UtilsForTesting u;
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");

  //Return success                                                              
  return u.NumberOfTestsFailed();
}
 
