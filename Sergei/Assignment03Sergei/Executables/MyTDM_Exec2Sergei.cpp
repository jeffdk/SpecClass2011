#include "DataMesh.hpp"

#include "Tensor.hpp"
#include <cstdlib>

int main(void) {
  const Mesh m(IPoint(MV::fill,2,2));
  Tensor<DataMesh> t(3,"aa",m ,1.0); // Last argument is initial value of the
                                     // data for the DataMesh in each tensor
                                     // component (all the same), default is 0.
  std::cout<<t(0).Extents()<<std::endl;
  t(1,1).Size(); // refers to the Mesh::Size() function
  t(1,1).Dim(); // refers to the Mesh::Dim() function -> value=2
  t.Dim(); // refers to the TensorStructure::Dim() function -> value=3
  std::cout<<t(1,1).Size()<<std::endl;
  std::cout<<t(1)<<std::endl;
  t(1,1)[0]= 10;
  
  std::cout<<t(1,1)<<std::endl;
  std::cout<<t<<std::endl;
  return EXIT_SUCCESS;
}
