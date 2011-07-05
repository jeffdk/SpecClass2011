#include <iostream>
#include <cstdlib>

#include "UtilsForTesting.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp" 
#include "MyVector.hpp"
#include "Require.hpp"
#include "Assignment02Aaron.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                     
 
  //First, read in some vectors from the file Vectors.input                     
 
  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  const double C = p.Get<double>("ParamToDivide");

  //Right away test to see if C is nonzero

  
  //I am commenting this out, it will ensure the divisor is nonzero using REQUIRE
  //REQUIRE(C!=0.0, "Error: divide by zero!\n");
  //Now I will use UtilsForTesting to run the test
  
  UtilsForTesting u;
  IS_TRUE(C!=0.0,"Divisor is zero.");
  //Test should fail is C=0.

  //Add the vectors together, divide by C                                   
 
  MyVector<double> result = sumVectors(A,B,C);
 
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Divisor C = " << C << std::endl;  
  std::cout << "Sum      = " << result << std::endl;
 

  //Test that the result magnitude is zero                                      
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");
  
  //Return success                                                              
  return u.NumberOfTestsFailed();
}
