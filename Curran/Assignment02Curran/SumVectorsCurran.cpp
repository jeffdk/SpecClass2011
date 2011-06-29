#include "SumVectorsCurran.hpp"

#include "MyVector.hpp"
#include "Require.hpp"
 
MyVector<double> sumVectors(const MyVector<double>& A,
                            const MyVector<double>& B) {
  // Make a new MyVector<double> of the same size as the addends and fill
  //   each element with zero
  REQUIRE(A.Size() == B.Size(), "Addends must be the same size");
  const int vectorSize = A.Size();
  MyVector<double> sum(MV::Size(vectorSize), 0.0);
 
  // Add the vectors component-by-component
  // Use the MyVector member function operator[](int i) which returns the
  //   the ith component of the vector.
  for(int i = 0; i < vectorSize; ++i) {
    sum[i] = A[i] + B[i];
  }
 
  // Return the result
  return sum;
}

