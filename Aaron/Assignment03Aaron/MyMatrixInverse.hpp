///////////////////////////////////////////////////////////////////////////////
/// MyMatrixInverse
///
/// This function accepts a tensor data mesh, and the mesh itself, and then 
/// outputs its inverse.
/// If the determinant vanishes somewhere on the mesh
/// it should give an error.
///
/// @param t          tensor data mesh
/// @param m          underlying mesh
/// @return           the inverse of t inverse
///
///////////////////////////////////////////////////////////////////////////////

Tensor<DataMesh> invert(const Tensor<DataMesh>& t, const Mesh& m);
