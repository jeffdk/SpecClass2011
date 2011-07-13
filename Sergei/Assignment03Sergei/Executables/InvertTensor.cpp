#include "DataMesh.hpp"
#include<cstdlib>
#include "Tensor.hpp"
#include "Assignment03Sergei.hpp"
#include <stdlib.h>
#include <time.h>
int main(void) {
  const Mesh m(IPoint(MV::fill,2,2));
  Tensor<DataMesh> t(3,"aa",m ,0.0);
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){

      for(int k=0;k<m.Size();k++){
	srand ( time(NULL) );
	 t(i,j)[k]=rand()/((k+1)*10);

      }
    }


  }
 
  
  Tensor<DataMesh> inv = findInverse(t);
  Tensor<DataMesh> inv2 = findInverse(inv);
  
  checkInverse(inv,inv2);
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){

      
      std::cout<<inv(i,j)-inv2(i,j)<<std::endl;
    }
  }
  
  
  return EXIT_SUCCESS;
}
