#ifndef ASSIGNMENT03CURRAN_MATRIXUTILS3X3CURRAN_HPP_
#define ASSIGNMENT03CURRAN_MATRIXUTILS3X3CURRAN_HPP_

#include "DataMesh.hpp"
#include "Tensor.hpp"

namespace Assignment03Curran {

/**
 * Compute the determinant of a 3x3 symmetric tensor.
 *
 * @param   mat The 3x3 symmetric tensor to take the determinant of
 * @return  The determinant of mat at every point in the mesh
 */
DataMesh Determinant3x3Sym(const Tensor<DataMesh>& mat);

/**
 * Compute the inverse of a 3x3 symmetric tensor.  
 *
 * @param   mat The 3x3 symmetric tensor to take the inverse of
 * @return  The inverse of mat at every point.
 */
Tensor<DataMesh> Inverse3x3Sym(const Tensor<DataMesh>& mat);

/**
 * Multiply two symmetrix 3x3 tensors as matrices.
 *
 * @param   a The first factor
 * @param   b The second factor
 * @return  The product of a and b
 */
Tensor<DataMesh> Multiply3x3Sym(const Tensor<DataMesh>& a,
                                const Tensor<DataMesh>& b);

/**
 * Fills a 3x3 symmetric tensor with random numbers in each component at each
 * mesh point.
 *
 * @param   mat The 3x3 symmetric tensor to fill with random data
 */
void Random3x3Sym(int seed, Tensor<DataMesh>& mat);

}

#endif // ASSIGNMENT03CURRAN_MATRIXUTILS3X3CURRAN_HPP_

