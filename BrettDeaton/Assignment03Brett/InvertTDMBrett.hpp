//////////////////////////////////////////////////////////////////////////
/// Cofactor
///
/// Compute the cofactor of element (a,b) of a 3D tensor
///
/// @param A     Tensor<DataMesh> we want to compute a cofactor of
/// @param a     first index
/// @param b     second index
/// @return      DataMesh corresponding to cofactor A(a,b)
//////////////////////////////////////////////////////////////////////////
/// MatrixMultiply
///
/// Compute the product of two 3D tensor fields
///
/// @param A     first Tensor<DataMesh> to multiply
/// @param B     second Tensor<DataMesh> to multiply
/// @return      Tensor<DataMesh> corresponding to A*B
///
/// @require     A & B are expected to be symmetric, but A*B is not in general
//////////////////////////////////////////////////////////////////////////
/// InvertTDM
///
/// Compute the inverse of a rank-2 3D tensor field
///
/// @param A     Tensor<DataMesh> we wish to invert
/// @return      Tensor<DataMesh> corresponding to A^{-1}
///
/// @require     A is expected to be symmetric, A^{-1} will also be
//////////////////////////////////////////////////////////////////////////      
 
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"

DataMesh Cofactor(const Tensor<DataMesh>& A, const int a, const int b);
Tensor<DataMesh> MatrixMultiply(const Tensor<DataMesh>& A, const Tensor<DataMesh>& B);
Tensor<DataMesh> InvertTDM(const Tensor<DataMesh>& A);
