#include <iostream>
#include <cstdlib>
 
#include "MyVector.hpp"
#include "MyFirstTestjeffdk.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                         
 
  //First, create a couple of vectors, then add them together                   
 
  const MyVector<double> A(MV::fill, 3.,4.,5.);
  const MyVector<double> B(MV::fill, 6.,7.,8.);
 
  //Next, make a vector to store the result                                     
 
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Add the vectors together                                                    
 
  result = sumVectors(A,B);
 
  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Sum      = " << result << std::endl;
 
  //Return success                                                              
  return EXIT_SUCCESS;;
}
 
