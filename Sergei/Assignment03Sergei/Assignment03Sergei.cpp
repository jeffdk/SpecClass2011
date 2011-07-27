#include "DataMesh.hpp"
#include "Tensor.hpp"
#include "Assignment03Sergei.hpp"
#include "Require.hpp"
#include<cstdlib>
#include <cmath>

DataMesh computeDet(const Tensor<DataMesh>& T){
/**
   Compute the determinant of the given tensor.
 */
  const Mesh m(T(0).Extents());
  DataMesh det(m);
  det = T(0,0)*T(1,1)*T(2,2)+T(0,1)*T(1,2)*T(2,0)+T(0,2)*T(1,0)*T(2,1) - T(0,0)*T(1,2)*T(2,1) - T(0,1)*T(1,0)*T(2,2)-T(0,2)*T(1,1)*T(2,0);
  
  return det;
}

Tensor<DataMesh> findInverse(const Tensor<DataMesh>& T){
  /**

     Compute the inverse of the given Tensor using a minor expansion.
   */
  const Mesh m(T(0).Extents());
  DataMesh det = computeDet(T);
  for(int k=0;k<det.Size();k++){
    REQUIRE(det[k]>1e-15 || det[k]<1e-15,"determinant is too close to zero!\n");
  }
  //The inverse of a symmetric matrix is symmetric:
  Tensor<DataMesh> inverse(3,"aa",m,0.0);
  inverse(0,0) = (T(1,1)*T(2,2)-T(1,2)*T(2,1))/det;
  inverse(0,1) = -(T(1,0)*T(2,2)-T(1,2)*T(2,0))/det;
  inverse(0,2) = (T(1,0)*T(2,1)-T(1,1)*T(2,0))/det;
  inverse(1,1) = (T(0,0)*T(2,2)-T(0,2)*T(2,0))/det;
  inverse(1,2) = -(T(0,0)*T(2,1)-T(0,1)*T(2,0))/det;
  inverse(2,2) = (T(0,0)*T(1,1)-T(0,1)*T(1,0))/det;
 
  return inverse;
}


bool checkInverse(Tensor<DataMesh>& A, Tensor<DataMesh>& B){
  /**
     Checks that a tensor and its inverse are equal to within roundoff
   */
  for(int i=0;i<A.Dim();i++){
    for(int j=0;j<B.Dim();j++){
      for(int k=0;k<A(0).Size();k++){
	double d = A(i,j)[k]-B(i,j)[k];

	REQUIRE(d<1e-14 && d>-1e-14, "Tensor and it's inverse are not the same");
      }
    }
  }
  return true;
}
