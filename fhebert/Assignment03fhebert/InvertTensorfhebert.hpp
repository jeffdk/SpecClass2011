//
// francois hebert, jul 2011
//
// this library provides the functions needed to invert
// a tensor (3x3 ONLY) of datameshes.
//


//=========================================================
// this function calculates the determinant of a given 
// 3x3 tensor and outputs it as a rank-0 tensor
//=========================================================
Tensor<DataMesh> DetTensor( const Tensor<DataMesh> & Tin );


//=========================================================
// this function calculates the inverse of a 3x3 tensor
// it starts by checking that the determinant is non-zero
//=========================================================
Tensor<DataMesh> InvTensor( const Tensor<DataMesh> & Tin );

