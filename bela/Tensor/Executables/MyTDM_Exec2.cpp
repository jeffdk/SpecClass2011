#include <DataMesh.hpp>
#include <Tensor.hpp>  
int main(void) {
  const Mesh m(IPoint(MV::fill,2,2));
  Tensor<DataMesh> t(3,"aa",m );
  t(1,1).Size(); // refers to the Mesh::Size() function
  t(1,1).Dim(); // refers to the Mesh::Dim() function -> value=2
  t.Dim(); // refers to the TensorStructure::Dim() function -> value=3
  
  Tensor<DataMesh> scalar(3,"",m,0.0); // this is a rank-0 tensor, initialized to zero
  scalar() += t(1,1); // add to the DataMesh inside 'scalar' the value of t(1,1)
  return 0;
}