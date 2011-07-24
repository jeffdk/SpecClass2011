#include <iostream>
#include <cstdlib>
#include "MyVector.hpp"
#include "Volume_fatemeh.hpp"

int main(){
  const MyVector<double> A(MV::fill,1.0,1.0,1.0,1.0);
  double TotalV =  TotalVolumeOfSpheresFromRadii(A);
  std::cout<< "Total Volume = "<< TotalV <<std::endl;
}
