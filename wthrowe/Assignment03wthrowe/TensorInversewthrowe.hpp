#include "Tensor.hpp"
#include "DataMesh.hpp"
void TensorInverse(const Tensor<DataMesh>& t, Tensor<DataMesh>& inv);
void TensorDeterminant(const Tensor<DataMesh>& t, DataMesh& det);
