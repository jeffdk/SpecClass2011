#include "DataMesh.hpp"
#include "Tensor.hpp"
#include <cstdlib>

int main(void) {
  const Mesh m(Ipoint(MV::fill,2,2));
  Tensor<DataMesh> t(3, "aa", m);
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<m.Size();k++){
	srand ( time(NULL) );
	t(i,j)[k]=rand()%10+1;
      }
    }
  }

  Tensor<DataMesh> inverse = ComputeInverse(t);
  Tensor<DataMesh> check = ComputerInverse(inverse);

  CheckInverse(t,check);

  return EXIT_SUCCESS;
}
