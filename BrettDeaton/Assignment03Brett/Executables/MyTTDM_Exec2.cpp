#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include <cstdlib>
 
int main(void) {
  const Mesh m(IPoint(MV::fill,3,3,3));
  const TensorStructure sPsi(4,"11"); // rank-2, symmetric, 3+1
  Tensor<DataMesh> Psi(sPsi,m,0); // metric
  for(int k=1;k<Psi.Dim();++k) Psi(k,k) = 1;
  Psi(0,0) = -1;
 
  // for the 1st derivative index: we need a rank-1 structure, i.e.,
  // we have SOMETHING_{,k}, the derivative of SOMETHING has a single index
  const TensorStructure sd1(3,"1"); // rank-1, 3D
 
  Tensor<Tensor<DataMesh> > dPsi(sPsi, sd1, m, 0);
 
  // for the indices of a 2nd derivative we want to enforce symmetry
  // in the derivative indices as well
 
  const TensorStructure sd2(3,"11"); // rank-1, 3D
 
  Tensor<Tensor<DataMesh> > d2Psi(sPsi, sd2, m, 0);
 
  // you can refer to these derivatives as dPsi(i,j)(k) or d2Psi(i,j)(m,n)
 
  std::cout << "psitt_x= "<<dPsi(0,0)(0) << "\n";
  std::cout << "psixx_yz = " << d2Psi(1,1)(1,2) << "\n";
 
  return EXIT_SUCCESS;
}
