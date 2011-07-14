#include "DataMesh.hpp"
#include "Tensor.hpp"
#include <cstdlib>
     
int main(void) {
  TensorStructure s1(3,"ab");
  TensorStructure s2(3,"b");
  const Mesh m(IPoint(MV::fill,2,2));
  Tensor<DataMesh> t1(s2,m,0.0); // will initialize all elements to zero
  Tensor<Tensor<DataMesh> > tt1(s1, t1); // will be a tensor of tensors, with all elements being zero
  Tensor<Tensor<DataMesh> > tt2(s1,s2, m, 0.0); // this gives the same result
  std::cout << "tt2(1,2)="<<tt2(1,2) <<"\n"; // will print out a Tensor<DataMesh>
  std::cout << "tt2(1,2)(0)="<<tt2(1,2)(0) <<"\n"; // will print out a single DatMesh
  // tt2(1,2) = 15; // will fail to compile
  tt2(1,2) = t1;    // this is fine
  tt2(1,2)(0) = -3; // will be fine.
     
  return EXIT_SUCCESS;
}
