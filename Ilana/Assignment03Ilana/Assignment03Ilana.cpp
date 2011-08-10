#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include <cstdlib>
#include "StudentProjects/SpecClass2011/Ilana/Assignment03Ilana/Assignment03Ilana.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include <cmath>


Tensor<DataMesh> ComputeInverse(const Tensor<DataMesh>& T){

  //Compute determinant
  const Mesh m(T(0).Extents());
  DataMesh det(m);
  det = T(0,0)*(T(1,1)*T(2,2) - T(1,2)*T(2,1)) + T(0,1)*(T(1,2)*T(2,0) - T(2,2)*T(1,0)) + T(0,2)*(T(1,0)*T(2,1) - T(1,1)*T(2,0));

  //Make sure the determinant isn't zero
  for(int i=0;i<det.Size();i++){
    REQUIRE(det[i]>1e-15 || det[i]<-1e-15,"determinant is very close to zero!\n");
  }

  //Find the inverse of the symmetric tensor
  Tensor<DataMesh> inverse(3,"aa",m);
  inverse(0,0) = (T(1,1)*T(2,2) - T(1,2)*T(2,1))/det;
  inverse(1,0) = (T(1,2)*T(2,0) - T(2,2)*T(1,0))/det;
  inverse(2,0) = (T(1,0)*T(2,1) - T(1,1)*T(2,0))/det;
  inverse(1,1) = (T(0,0)*T(2,2) - T(0,2)*T(2,0))/det;
  inverse(2,1) = (T(2,0)*T(0,1) - T(0,0)*T(2,1))/det;
  inverse(2,2) = (T(0,0)*T(1,1) - T(0,1)*T(1,0))/det;
  
  return inverse;
}

bool CheckInverse(Tensor<DataMesh>& A, Tensor<DataMesh>& B){
  
  //Make sure the tensor and inverse of the inverse are equal
  for(int i=0;i<A.Dim();i++){
    for(int j=0;j<B.Dim();j++){
      for(int k=0;k<A(0).Size();k++){
	double diff = A(i,j)[k] - B(i,j)[k];
	REQUIRE(diff<1e-14 && diff>-1e-14, "Tensor and the inverse of its inverse are not equal");
      }
    }
  }

  return true;
}
