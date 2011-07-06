#include <iostream>
#include <cstdlib>
 
#include "MyVector.hpp"
#include "Assignment02hohejd8.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "Require.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
  UtilsForTesting u;
  //Try out the new sumVectors function                                         
 
  //First, create a couple of vectors, then add them together                   
/* 
  const MyVector<double> A(MV::fill, 3.,4.,5.);
  const MyVector<double> B(MV::fill, 6.,7.,8.);
*/
  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double divisor = p.Get<double>("Divisor",1.0);
  REQUIRE(divisor!=0.0, "Error: divisor set to zero");
  IS_TRUE(divisor!=0.0, "Error: divisor is equal to zero");

  //Next, make a vector to store the result                                     
 
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Add the vectors together                                                    
 
  result = sumVectors(A,B,divisor);
 
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;

  //Test that the result magnitude is zero                                      
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");


  //Return success                                                              
  //return EXIT_SUCCESS;
  return u.NumberOfTestsFailed();
}
