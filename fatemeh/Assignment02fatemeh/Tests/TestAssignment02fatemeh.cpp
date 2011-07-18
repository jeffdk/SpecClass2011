#include <iostream>
#include <cstdlib>
#include<MyVector.hpp>
#include<Assignment02fatemeh.hpp>
#include <OptionParser.hpp>
#include <ReadFileIntoString.hpp>
#include <UtilsForTesting.hpp>

int main(int /*argc*/, char** /*argv*/){
  //MyVector<double> A(MV::fill, 3.0,4.0,5.0);
  //MyVector<double> B(MV::fill, 6.0,7.0,8.0);
  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FirstVectorToAdd");
  MyVector<double> B = p.Get<MyVector<double> >("SecondVectorToAdd");
  double C           = p.Get<double>("ConstantDoubleToDivide");
  MyVector<double> result(MV::Size(A.Size()),0.0);
  result = div_sumVectors(A,B,C);
  std::cout<<"Vector A ="<<A<<std::endl;
  std::cout<<"Vector B ="<<B<<std::endl;
  std::cout<<"double C ="<<C<<std::endl;
  std::cout<<"sum vectors divided by a constant= "<<result<<std::endl;
  double resultMagnitudeSq = 0.0;
  for(int i=0;i<result.Size();++i) {
    resultMagnitudeSq += result[i]*result[i];
  }
  UtilsForTesting u;
  UtilsForTesting w;
  IS_ZERO(resultMagnitudeSq,"Sum of vector and its negative nonzero.");
  //*** check if the double is zero.
  IS_TRUE(C!=0.0,"The constant double is zero.");
  return u.NumberOfTestsFailed();
  return w.NumberOfTestsFailed();
  //return EXIT_SUCCESS;
}
