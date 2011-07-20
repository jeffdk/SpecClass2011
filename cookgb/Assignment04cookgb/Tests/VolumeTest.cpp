#include <iostream>
#include <cstdlib>

#include "Volume_cookgb.hpp"
#include "MyVector.hpp"
#include "UtilsForTesting.hpp"

int main(int /*argc*/, char** /*argv*/) {

  // Try out the function TotalVolumeOfSpheresFromRadii

  // First set up 4 radii and the correct result
  const MyVector<double> TestRadii(MV::fill,1.5,2.5,3.5,4.5);
  const double CorrectVolume = 640.88490133231782065;

  // Call the new function
  const double TotalVolume = TotalVolumeOfSpheresFromRadii(TestRadii);
  
  std::cout << "Test Radii = " << TestRadii << std::endl;
  std::cout << "Total Volume = " << TotalVolume << std::endl;
  std::cout << "Volume relative error = "
	    << (CorrectVolume - TotalVolume)/CorrectVolume << std::endl;

  UtilsForTesting u;
  IS_ZERO_EPS(CorrectVolume-TotalVolume,"Returned incorrect volume");
 
  //Return success                                                              
  return UtilsForTesting::NumberOfTestsFailed();
}
