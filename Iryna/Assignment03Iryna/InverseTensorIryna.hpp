///////////////////////////////////////////////////////////////////////////////
/// InverseTensorIryna
///
/// This function takes two 3x3 Tensor<DataMesh> matrices as arguments. It then
/// finds the inverse of the first argument and outputs it into the second
/// argument. 
/// 
/// @param t       the matrix to be inverted
/// @param t_inv   the matrix that stores the inverted t matrix
///
///////////////////////////////////////////////////////////////////////////////

void InverseTensor(Tensor<DataMesh>& t, Tensor<DataMesh>& t_inv);
