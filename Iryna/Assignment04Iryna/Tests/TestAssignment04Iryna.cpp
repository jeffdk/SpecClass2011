#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "Require.hpp"
#include "Volume_Iryna.hpp"

int main(int /*argc*/, char** /*argv*/) {

  // First, create a couple of vectors, then add them together                   

  OptionParser p(ReadFileIntoString("Vectors.input"));
  MyVector<double> Radii = p.Get<MyVector<double> >("RadiiToUse"); 

  // Check that Radii doesn't hold a negative value
  const int vectorSize = Radii.Size();
  int num_negatives = 0; 
  for(int i = 0, i < vectorSize, i++){
    if(Radii[i] < 0.0){
      num_negatives++;
    }
  }
  UtilsForTesting u;
  IS_TRUE(num_negatives = 0.0, "ERROR: Radius can't be a negative value"); 

 
 // Next, make a vector to store the result                                     

  MyVector<double> TotalVolumes(MV::Size(Radii.Size()),0.);

  // Find the volumes using the radii                                                    

  TotalVolumes = TotalVolumeOfSpheresFromRadii(Radii);

  // Print out the results                                                       

  std::cout << "Radii = " << Radii << std::endl;
  std::cout << "Volumes = " << TotalVolumes << std::endl;

 
  //Return success                                                              
  return u.NumberOfTestsFailed();
}
  
