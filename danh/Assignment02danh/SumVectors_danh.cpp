#include "SumVectors_danh.hpp"
#include "Utils/ErrorHandling/Assert.hpp"

/// Implements function SumVectors 
MyVector<double> SumVectors(const MyVector<double>& A,
                            const MyVector<double>& B,
                            const double divisor)
{
  // Error checking
  ASSERT(A.Size() == B.Size(), "Error: vectors not the same size.");
  ASSERT(divisor != 0.0, "Error: divisor must not be zero.");

  // Add the vectors component-by-component
  // Use the MyVector member function operator[](int i) which returns the
  // the ith component of the vector.
  MyVector<double> Sum(MV::Size(A.Size()), 0.0);
  for(int i=0; i<Sum.Size(); ++i) {
    Sum[i] = (A[i] + B[i])/divisor;
  }

  //Return the result
  return Sum;
}
