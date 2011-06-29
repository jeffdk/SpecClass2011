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

  REQUIRE(A.Size()==B.Size(),"Error: The two vectors must be the same size.");
  
  //Next, make a vector to store the result
  MyVector<double> result = sumVectors(A,B);
 
  //Test that the result is zero
  UtilsForTesting u;
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");
 
  //Print out the results
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;
 
  //Return success
  return u.NumberOfTestsFailed();
}
