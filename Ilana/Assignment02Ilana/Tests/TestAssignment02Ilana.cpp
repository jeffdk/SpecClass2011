#include <iostream>
#include <cstdlib>
 
#include "MyVector.hpp"
#include "Assignment02Ilana.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                         
 
  //First, create a couple of vectors, then add them together                   
 
  //const MyVector<double> A(MV::fill, 3.,4.,5.);
  //const MyVector<double> B(MV::fill, 6.,7.,8.);

  //First, read in some vectors from the file Vectors.input
 
  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double C = parser.Get<double>("Divisor");
 
  //Next, make a vector to store the result                                     
 
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Test that the vectors are the same size                                    
  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size.\n");

  //Test that C is not equal to zero
  REQUIRE(C !=0.0, "Error: don't divide by zero!");

  //Add the vectors together                                                    
 
  result = sumVectors(A,B,C);
 
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Double C = " << C << std::endl;
  std::cout << "Sum      = " << result << std::endl;

  //Test again that C is not equal to zero
  UtilsForTesting u;
  IS_TRUE(C!=0.0, "Divisor C should not be zero!");

  //Test that the result magnitude is zero                                      
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  UtilsForTesting u;
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");
 
  //Return success                                                              
  // return EXIT_SUCCESS;;
  
  //Return the number of tests that have failed.
  return u.NumberOfTestsFailed();
}
