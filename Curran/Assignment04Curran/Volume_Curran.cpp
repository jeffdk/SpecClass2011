#include "Volume_Curran.hpp"

#include "MyVector.hpp"

double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii) {
    const double pi = 3.1415926535897932; // C99 removed M_PI from math.h

    double vol_tot = 0.0; // Total volume will be accumulated here

    // For each sphere, add its volume to the total
    for (int i = 0; i < radii.Size(); ++i) {
        // The volume of a sphere is: 4/3 pi r^3
        const double r = radii[i];
        vol_tot += (4.0/3.0)*pi*r*r*r;
    }

    return vol_tot;
}

