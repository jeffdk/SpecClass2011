#include <iostream>
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"

Tensor<DataMesh> add(const Tensor<DataMesh>& a,const Tensor<DataMesh>& b) {
  REQUIRE(a.Structure()==b.Structure(),"Structure mismatch");

  Tensor<DataMesh> result = a;
  Tensor<DataMesh>::iterator ita       = result.begin();
  Tensor<DataMesh>::const_iterator itb = b.begin();
  for(;ita!=result.end();++ita,++itb)  *ita += *itb;

  return result;
}
int main() {
  const Mesh mesh(MyVector<int>(MV::fill,30,30,30));

  const Tensor<DataMesh> a(4,"12",mesh,3.0);
  const Tensor<DataMesh> b(4,"12",mesh,5.0);
  const Tensor<DataMesh> c = add(a,b);

  std::cout << c.Structure() << std::endl;
}
