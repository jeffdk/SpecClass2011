///
/// francois hebert, jul 2011
///
/// this library provides functions on vectors
///
/// sumVectors : a function to sum together two vectors.
/// takes in two vectors A,B
/// checks that lengths match before adding component-wise
/// returns a third vector C
///
/// scaleVector : multiplies a vector by a double
/// takes in a vector A and double d
/// returns a vector d*A
///


template<typename> class MyVector;

MyVector<double> sumVectors( const MyVector<double>& A, const MyVector<double>& B );
MyVector<double> scaleVector( const MyVector<double>& A, const double d );

