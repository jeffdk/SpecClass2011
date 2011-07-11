#include <iostream>
#include <cstdlib>
 
#include "Require.hpp"
#include "OptionParser.hpp"
#include "UtilsForTesting.hpp"
#include "ReadFileIntoString.hpp"
#include "MyVector.hpp"
#include "Assignment02Sergei.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                         
 
  //First, read in some vectors from the file Vectors.input                     
 
  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double C = p.Get<double>("Divisor");
  //Next, make a vector to store the result                                     
  //REQUIRE(C !=0.0,"Error: cannot divide by zero!\n");
  
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Add the vectors together                                                    
 
 result = sumVectorsAndDivide(A,B,C);
  UtilsForTesting u;
  IS_TRUE(C!=0.0,"Divisor !=0 should be true, cannot divide by zero!");
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Divisor = " <<  C << std::endl;
  std::cout << "Result      = " << result << std::endl;
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");
                                       
  return u.NumberOfTestsFailed();
}
