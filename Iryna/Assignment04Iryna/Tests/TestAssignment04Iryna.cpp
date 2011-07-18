#include <iostream>
#include <cstdlib>

#include "MyVector.hpp"
#include "OptionParser.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "Require.hpp"
#include "Volume_Iryna.hpp"

int main(int /*argc*/, char** /*argv*/) {

 /* // First, create a couple of vectors, then add them together                   

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
  IS_TRUE(num_negatives = 0.0, "ERROR: Radius can't be a negative value"); */

 // First, make a vector of Radii to test
 const MyVector<double> Radii(MV::fill, 1.1);

 // Next, make a vector to store the result                                     

  double TotalVolume = 0;

  // Find the volumes using the radii                                                    

  TotalVolume = TotalVolumeOfSpheresFromRadii(Radii);
  const double expectedTotalVolume =  5.575279762570688;//200.71007145254467; 
  const double tolerance = 1.0E-6;

  UtilsForTesting u;
  IS_TRUE(TotalVolume == expectedTotalVolume, "ERROR: The \
	calculated total volume does not match the expected"); 

  // Print out the results                                                       

  std::cout << "Radii = " << Radii << std::endl;
  std::cout << "Total Volume = " << TotalVolume << std::endl;

 
  //Return success                                                              
  return u.NumberOfTestsFailed();
}
  
