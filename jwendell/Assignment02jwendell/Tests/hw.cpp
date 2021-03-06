#include <iostream>
#include <cstdlib>
 
#include "Utils/MyContainers/MyVector.hpp"
#include "StudentProjects/SpecClass2011/jwendell/Assignment02jwendell/Assignment02jwendell.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp" 
#include "Utils/ErrorHandling/UtilsForTesting.hpp"


int main(int /*argc*/, char** /*argv*/) {
 
  //Try out the new sumVectors function                                         
 
  //First, create a couple of vectors, then add them together                   
  OptionParser p(ReadFileIntoString("VectorsDiv.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double C = p.Get<double>("DivisionConstant");

  
  //const MyVector<double> A(MV::fill, 3.,4.,5.);
  //const MyVector<double> B(MV::fill, 6.,7.,8.);
 
  //Next, make a vector to store the result                                     
 
  MyVector<double> result(MV::Size(A.Size()),0.);
 
  //Add the vectors together                                                    
  if(C != 0.0)
    result = sumVectorsDiv(A,B,C);

  //Print out the results                                                       
 
  std::cout << "Vector A = " << A << std::endl;
  std::cout << "Vector B = " << B << std::endl;
  std::cout << "Divide by C = " << C << std::endl;
  std::cout << "Sum      = " << result << std::endl;


  //Test that the result magnitude is zero
  //double resultMagnitudeSq = 0.0;
  //for(int i=0;i<result.Size();++i){
  //  resultMagnitudeSq += result[i]*result[i];
  //}
  UtilsForTesting u;
  IS_TRUE(C!=0.0,"Dividing by zero!");
 
  //Return success                                                              
  return u.NumberOfTestsFailed();
}
