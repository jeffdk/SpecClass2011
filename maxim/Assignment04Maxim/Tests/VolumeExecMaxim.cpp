#include <iostream>
#include <cmath> // for Pi
#include "MyVector.hpp"
#include "Volume_Maxim.hpp"
#include "CorrectVolume_Maxim.hpp"
#include "UtilsForTesting.hpp"

using namespace std;

int main() {
	const MyVector<double> radii(MV::fill, 1.0, 1.5, 2.0, 3.0);
	double trueVolume = 0.0, funcVolume = 0.0, myfuncVolume = 0.0;
	
	UtilsForTesting u;
	for(int i = 0; i < radii.Size(); i++)
		trueVolume += (4.0/3.0)*M_PI*radii[i]*radii[i]*radii[i];
	
	funcVolume = TotalVolumeOfSpheresFromRadii(radii);
	myfuncVolume = CorrectTotalVolumeOfSpheresFromRadii(radii);

	cout << "trueVolume	= " << trueVolume << endl;
	cout << "funcVolume	= " << funcVolume << endl;
	cout << "myfuncVolume	=" << myfuncVolume << endl;

	IS_TRUE(trueVolume == funcVolume, "The output of TotalVolumeOfSpheresFromRadii() is incorrect\n");
	IS_TRUE(trueVolume == myfuncVolume, 
			"The output of CorrectTotalVolumeOfSpheresFromRadii() is incorrect\n");

	return u.NumberOfTestsFailed();
}
