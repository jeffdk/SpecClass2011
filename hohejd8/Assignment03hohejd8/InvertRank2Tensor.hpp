/** Returns the inverse of a rank 2, 3x3 tensor (matrix).
*/

#include "DataMesh.hpp"
#include "Tensor.hpp"
#include <cstdlib>

void InvertRank2Tensor(const Tensor<DataMesh> & T,
                       Tensor<DataMesh> & InvT);

DataMesh Determinant(const Tensor<DataMesh> & T);
