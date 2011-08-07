#include <iostream>
#include <cstdlib>
 
#include "Utils/MyContainers/MyVector.hpp"
#include "StudentProjects/SpecClass2011/maxim/Assignment02Maxim/Assignment02Maxim.hpp"

#include "Utils/StringParsing/OptionParser.hpp" 
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "Utils/ErrorHandling/Require.hpp"

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
  REQUIRE(d != 0, "Error: divider is zero");

  //Add the vectors together                                                    
  result = sumVectorsDivided(A,B,d);
  //bug
  //result = A; 
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  //Test that the result magnitude is zero  
  REQUIRE(resultMagnitudeSq == 0, "The result magnitude is not zero\n");

  //Print out the results                                                        
  cout << "Vector A = " << A << endl;
  cout << "Vector B = " << B << endl;
  cout << "Sum divided by " << d << " = " << result << endl;
 

  //Return success                                                              
  return EXIT_SUCCESS;
}
