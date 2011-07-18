//////////////////////////////////////////////////////////////////////////      
/// Assignment03Sergei                                                         
///                                                                             
/// Compute the inverse of a given 3x3 symmetric Tensor<DataMesh>
///                                                                             
/// @param T     Tensor to be inverted, should be 3x3 symmetric                                            
/// @return      The inverse of the input tensor                                        
///                                                                             
////////////////////////////////////////////////////////////////////////// 


Tensor<DataMesh> findInverse(const Tensor<DataMesh>& T);
DataMesh computeDet(const Tensor<DataMesh>& T);
bool checkInverse(Tensor<DataMesh>& A, Tensor<DataMesh>& B);
