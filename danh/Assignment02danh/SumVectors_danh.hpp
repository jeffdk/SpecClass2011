/// Declares function SumVectors
///
/// This function adds two MyVector<double>'s together component-wise,
/// divides each component by some factor, and returns the result. The
/// vectors must be the same size.
///
/// @param A        first vector
/// @param B        second vector
/// @param divisor  factor that divides each component
/// @return         (A+B)/divisor
 
#include "Utils/MyContainers/MyVector.hpp"

MyVector<double> SumVectors(const MyVector<double>& A,
                            const MyVector<double>& B,
                            const double divisor);
