#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include <cstdlib>
#include "InverseTensorIryna.hpp"
/home/ibutsky/gccdebug/Utils/DataMesh
void InverseTensor(Tensor<DataMesh>& t, Tensor<DataMesh>& t_inv) {
  
  // make sure both tensors have right dimensions 
  REQUIRE(t.Structure() == TensorStructure(3, "aa"), "Error: Tensor must be \
			3x3 and symmetric");
  REQUIRE(t_inv.Structure() == TensorStructure(3, "aa"), "Error: Tensor must \
			be 3x3 and symmetric");

  DataMesh det = t(0,0)*t(1,1)*t(2,2) + t(0,1)*t(1,2)*t(2,0) + \
	t(0,2)*t(1,0)*t(2,1) - t(0,0)*t(1,2)*t(2,1) - t(0,1)*t(1,0)*t(2,2) \
	- t(0,2)*t(1,1)*t(2,0);

  // check that the determinant is nonzero
  int num_zeros = 0;
  for(int i=0; i<det.Size(); i++){
    if(det[i] == 0){
      num_zeros++;
    }
  }
  REQUIRE(num_zeros == 0, "Error: The determinant of the tensor is 0");

  t_inv(0,0) = (t(2,2)*t(1,1) - t(2,1)*t(1,2))/det;
  t_inv(0,1) = (t(2,1)*t(0,2) - t(2,2)*t(0,1))/det;
  t_inv(0,2) = (t(1,2)*t(0,1) - t(1,1)*t(0,1))/det;
  t_inv(1,0) = (t(2,0)*t(1,2) - t(2,2)*t(1,0))/det;
  t_inv(1,1) = (t(2,2)*t(0,0) - t(2,0)*t(0,2))/det;
  t_inv(1,2) = (t(1,0)*t(0,2) - t(1,2)*t(0,0))/det;
  t_inv(2,0) = (t(2,1)*t(1,0) - t(2,0)*t(1,1))/det;
  t_inv(2,1) = (t(2,0)*t(0,1) - t(2,1)*t(0,0))/det;
  t_inv(2,2) = (t(1,1)*t(0,0) - t(1,0)*t(0,1))/det;
  

}

