#include <iostream>
#include <cstdlib>

#include "OptionParser.hpp"
#include "MyVector.hpp"
#include "Assignment02cookgb.hpp"
#include "ReadFileIntoString.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                         
 
  //First, read in some vectors from the file Vectors.input                     
 
  OptionParser p(ReadFileIntoString("Vectors.input"));
  const MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  const MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
 
  //Add the vectors together and store the result 
  const MyVector<double> result = sumVectors(A,B);
 
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;
 
  //Return success                                                              
  return EXIT_SUCCESS;
}
