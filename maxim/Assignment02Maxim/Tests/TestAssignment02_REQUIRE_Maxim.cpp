#include <iostream>
#include <cstdlib>
 
#include "MyVector.hpp"
#include "Assignment02Maxim.hpp"

#include "OptionParser.hpp" 
#include "ReadFileIntoString.hpp"
#include "Require.hpp"

using namespace std;

int main(int /*argc*/, char** /*argv*/) {
  //Try out the new sumVectors function                                         
 
  //First, create a couple of vectors, then add them together                   
 
  //const MyVector<double> A(MV::fill, 3.,4.,5.);
  //const MyVector<double> B(MV::fill, 6.,7.,8.);
  
  OptionParser p(ReadFileIntoString("Vectors.input"));
  
  MyVector <double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector <double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  	
  //Next, make a vector to store the result                                     
 
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Test that the vectors are the same size                                    
  REQUIRE(A.Size() == B.Size(), "Error: vectors not the same size.\n");
  
  double d = p.Get<double>("Divider");
  REQUIRE(d != 0, "Error: divider is zero")

  //Add the vectors together                                                    
  result = sumVectorsDivided(A,B,d);
  //bug
  //result = A; 

  //Print out the results                                                       
 
  cout << "Vector A = " << A << endl;
  cout << "Vector B = " << B << endl;
  cout << "Sum divided by " << d << " = " << result << endl;
 

  //Return success                                                              
  return EXIT_SUCCESS;
}
