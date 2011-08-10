#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
void TensorInverse(const Tensor<DataMesh>& t, Tensor<DataMesh>& inv);
void TensorDeterminant(const Tensor<DataMesh>& t, DataMesh& det);
