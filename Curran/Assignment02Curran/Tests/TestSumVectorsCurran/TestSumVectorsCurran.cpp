#include <cstdlib>
#include <iostream>
 
#include "SumVectorsCurran.hpp"
#include "MyVector.hpp"
#include "ReadFileIntoString.hpp"
#include "OptionParser.hpp"
#include "UtilsForTesting.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
  // Try out the new sumVectors function

  // First, create a couple of vectors, then add them together
  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
 
  // Next, make a vector to store the result
  MyVector<double> result = sumVectors(A, B);
 
  // Print out the results
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;
 
  // Return success
  return UtilsForTesting::NumberOfTestsFailed();
}

