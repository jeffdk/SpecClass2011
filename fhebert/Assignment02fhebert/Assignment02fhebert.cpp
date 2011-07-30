//
// francois hebert, jul 2011
//
// implementation of:
// vector addition
// vector*scalar multiplication
//


#include "Assignment02fhebert.hpp"
#include "Utils/MyContainers/MyVector.hpp"


MyVector<double> sumVectors(const MyVector<double>& A, const MyVector<double>& B)
{
  const int size = A.Size();
  MyVector<double> sum(MV::Size(size), 0.0);

  for (int i=0; i<size; ++i) 
  {
    sum[i] = A[i]+B[i];
  }

  return sum;
}


MyVector<double> scaleVector(const MyVector<double>& A, const double d)
{
  const int size = A.Size();
  MyVector<double> scale(MV::Size(size), 0.0);

  for (int i=0; i<size; ++i )
  {
    scale[i] = d * A[i];
  }

  return scale;
}
