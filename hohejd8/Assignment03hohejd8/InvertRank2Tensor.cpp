#include "InvertRank2Tensor.hpp"

void InvertRank2Tensor(const Tensor<DataMesh> & T, Tensor<DataMesh> &  InvT){
  //check to see that the tensor is invertible
  REQUIRE(T.Structure()==TensorStructure(3,"aa"),
          "Inverse cannot be computed; input is not a 3x3 symmetric tensor.");

  DataMesh det = Determinant(T);

  for(int i=0; i<det.Size(); i++){
    REQUIRE(det[i]!=0.0, 
         "The determinant of this tensor is zero at some point");
  }

  //compute inverse of tensor, assuming symmetry
  InvT(0,0) = (T(1,1)*T(2,2) - T(1,2)*T(2,1))/det;
  InvT(0,1) = (T(2,1)*T(0,2) - T(2,2)*T(0,1))/det;
  InvT(0,2) = (T(0,1)*T(1,2) - T(0,2)*T(1,1))/det;
  InvT(1,1) = (T(2,2)*T(0,0) - T(2,0)*T(0,2))/det;
  InvT(1,2) = (T(0,2)*T(1,0) - T(0,0)*T(1,2))/det;
  InvT(2,2) = (T(0,0)*T(1,1) - T(0,1)*T(1,0))/det;
  InvT(1,0) = InvT(0,1);
  InvT(2,0) = InvT(0,2);
  InvT(2,1) = InvT(1,2);

}

DataMesh Determinant(const Tensor<DataMesh> & T){
  //compute determinant of tensor
  DataMesh det = T(0,0)*T(1,1)*T(2,2) + T(0,1)*T(1,2)*T(2,0) +
               T(0,2)*T(1,0)*T(2,1) - T(0,0)*T(1,2)*T(2,1) -
               T(0,1)*T(1,0)*T(2,2) - T(0,2)*T(1,1)*T(2,0);

  return det;
}
