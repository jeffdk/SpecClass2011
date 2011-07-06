#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "Require.hpp"
#include "Assignment02Iryna.hpp"

int main(int /*argc*/, char** /*argv*/) {

  //Try out the new sumVectors function                                         

  //First, create a couple of vectors, then add them together                   

  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  const double C = p.Get<double>("DoubleToDivideBy");

  // Check that C isn't equal to 0
  UtilsForTesting u;
  IS_TRUE(C != 0.0, "ERROR: DoubleToDivideBy can't be 0.0"); 
  //REQUIRE(divisor != 0.0, "ERROR: DoubleToDivideBY can't be 0.0"); 

  //Next, make a vector to store the result                                     

  MyVector<double> result(MV::Size(A.Size()),0.);

  //Add the vectors together                                                    

  result = addDivideVectors(A,B,C);

  //Print out the results                                                       

  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Result      = " << result << std::endl;

  double resultMagnitudeSq = 0.0;
  for(int i=0; i<result.Size(); ++i){
    resultMagnitudeSq += result[i]*result[i];
  }
  
  IS_ZERO(resultMagnitudeSq, "Sum of vector and its negative nonzero.");
 
  //Return success                                                              
  return u.NumberOfTestsFailed();
}
  
