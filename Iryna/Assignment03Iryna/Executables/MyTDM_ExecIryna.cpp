#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/LowLevelUtils/Ran2Class.hpp"
#include <cstdlib>

#include "InverseTensorIryna.hpp"

int main(void){

  TensorStructure s(3, "aa");
  const Mesh m(IPoint(MV::fill,0,0));
  Tensor<DataMesh> t(s,m);
  Tensor<DataMesh> t_inv(s,m);

  srand(time(NULL));
  double k = rand()%100;
  std::cout<<k;
  // Assign random values to tensor
  for(int i=0; i<t.Dim(); i++){
    for(int j=0; j<t.Dim(); j++){
       srand(time(NULL));
       t(j,k)[i] = (rand()%100)/100.0;
    }
  }
   
  InverseTensor(t, t_inv);

  std::cout << "The matrix is:" <<t<<"\n";
  std::cout << "The inverse matrix is:" <<t_inv<<"\n";

  return EXIT_SUCCESS;
  

}
