#ifndef ASSIGNMENT04CURRAN_VOLUME_CURRAN_HPP_
#define ASSIGNMENT04CURRAN_VOLUME_CURRAN_HPP_

template<typename> class MyVector;

/**
 * Compute the total volume of a set of spheres with the given radii.
 *
 * @param   radii The radii of the spheres whose volume should be totaled
 * @return  The total volume of the specified spheres
 */
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii);

#endif // ASSIGNMENT04CURRAN_VOLUME_CURRAN_HPP_

