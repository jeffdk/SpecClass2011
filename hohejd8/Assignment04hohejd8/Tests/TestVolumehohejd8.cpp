///Part of an automated test to see if the Volume_hohejd8 function works properly.

#include "Volume_hohejd8.hpp"
#include "ReadFileIntoString.hpp"
#include "UtilsForTesting.hpp"
#include "OptionParser.hpp"

int main(int /*argc*/, char** /*argv*/) {

  OptionParser p(ReadFileIntoString("Radii.input"));
  MyVector<double> A = p.Get<MyVector<double> >("FourRadii");
  IS_EQUAL(A.Size(), 4, "The input must contain exactly four components.");

  //Calls the routine for calculating the sum of the volumes
  double resultVolume = TotalVolumeOfSpheresFromRadii(A);

  //calculates the sum of the radii cubed
  double SumOfRadiiCubed = 0.0;
  for(int i=0; i<A.Size(); i++){
    SumOfRadiiCubed += A[i]*A[i]*A[i];
  }

  //compares the sum of radii cubed to total volume
  double radiiCubed = resultVolume / ((4.0/3.0)*3.1415926535897932);
  IS_EQUAL(radiiCubed, SumOfRadiiCubed,
        "The total volume of the spheres has been incorrectly evaluated.");

  //std::cout<< "Sum = " << SumOfRadiiCubed << " radiiCubed  = " << radiiCubed << std::endl;

  return UtilsForTesting::NumberOfTestsFailed();
}
