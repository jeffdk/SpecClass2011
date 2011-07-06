#include <iostream>
#include <cstdlib>
 
#include "MyVector.hpp"
#include "Assignment02Brett.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "Require.hpp"
#include "UtilsForTesting.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
 
  //First, create a couple of vectors, then add them together
  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  const double norm = p.Get<double>("Norm");

  REQUIRE(A.Size()==B.Size(),"Error: The two vectors must be the same size.");
  //  REQUIRE(norm!=0,"Error: Normalization factor must be nonzero.");
  
  //Next, make a vector to store the result
  MyVector<double> result = sumVectors(A,B,norm);
 
  //Test that the denominator is nonzero
  UtilsForTesting u;
  // double resultMagnitudeSq = 0.0;
  // for(int i=0;i<result.Size();++i) {
  //   resultMagnitudeSq += result[i]*result[i];
  // }
  // IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");
  IS_TRUE(norm!=0,"Division by zero.");
 
  //Print out the results
  std::cout << "Vector A  = " << A << std::endl;
  std::cout << "Vector B  = " << B << std::endl;
  std::cout << "Norm      = " << norm << std::endl;
  std::cout << "ScaledSum = " << result << std::endl;
 
  //Return success
  return u.NumberOfTestsFailed();
}
