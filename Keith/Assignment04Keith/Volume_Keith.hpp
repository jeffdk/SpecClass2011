/// \file
/// Defines function TotalVolumeOfSpheresFromRadii.
#ifndef Volume_Keith_hpp
#define Volume_Keith_hpp

template <typename> class MyVector;

/// Computes the sum of volumes of spheres whose radii are the 
/// components the MyVector argument.
double TotalVolumeOfSpheresFromRadii(const MyVector<double>& radii);

#endif  // Volume_Keith_hpp
