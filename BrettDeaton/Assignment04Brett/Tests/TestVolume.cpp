#include "Utils/MyContainers/MyVector.hpp"
#include "StudentProjects/SpecClass2011/BrettDeaton/Assignment04Brett/Volume_Brett.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/ErrorHandling/UtilsForTesting.hpp"

#include <iostream>
#include <cstdlib>
#include <cmath>
 
int main(int /*argc*/, char** /*argv*/) {
 
  OptionParser p(ReadFileIntoString("TestVolume.input"));
  const MyVector<double> radii = p.Get<MyVector<double> >("Radii");
  const double expectedSumVol = p.Get<double>("NetVolumeToE-3Precision");

  REQUIRE(radii.Size()==4,"Error: Radii must have 4 elements.");
  REQUIRE(expectedSumVol>=0,"Error: NetVolume must be nonnegative.");

  double sumVol = TotalVolumeOfSpheresFromRadii(radii);
 
  UtilsForTesting u;
  IS_TRUE(fabs(sumVol-expectedSumVol)<2e-3,
	  "The summed volume is not what was expected.");
 
  //Print out the results
  std::cout << "Radii = " << radii << std::endl;
  std::cout << "Expected Volume = " << expectedSumVol << std::endl;
  std::cout << "Calculated Volume (using TotalVolumeOfSpheresFromRadii) = " << sumVol << std::endl;
  if(u.NumberOfTestsFailed())
    std::cout << "TotalVolumeOfSpheresFromRadii failed to work to within 1e-3 accuracy." << std::endl;
  else
    std::cout << "TotalVolumeOfSpheresFromRadii works to within 1e-3 accuracy." << std::endl;

  //Return success
  return u.NumberOfTestsFailed();
}
