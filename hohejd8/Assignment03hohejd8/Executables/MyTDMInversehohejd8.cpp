#include "DataMesh.hpp"
#include "Tensor.hpp"
#include "InvertRank2Tensor.hpp"
#include <cstdlib>
 
int main(void) {
  //initialize mesh, Tensor<DataMesh>, and inverses
  //const Mesh m(IPoint(MV::fill,10,10));
  const Mesh m(IPoint(MV::fill,3,3,3));
  Tensor<DataMesh> Trand(3,"aa", m);
  Tensor<DataMesh> InvT(Trand.Structure(), m);
  Tensor<DataMesh> InvInvT(Trand.Structure(), m);

  //seed random number generator
  srand ( time(NULL) );

  //create random data for *symmetric* TDm in the range [0.0, 1.0)
  int mSize = m.Size();
  for(int i=0; i<3; i++){
    for(int j=i; j<3; j++){
      for(int k=0; k<mSize; k++){
        Trand(i,j)[k] = (rand()%1000)/1000.0;
      }
    }
  }

  //compute the inverse
  InvertRank2Tensor(Trand, InvT);

  //compute the inverse of the inverse
  InvertRank2Tensor(InvT, InvInvT);
  
  std::cout << "Tensor<DataMesh> inverse routine: \n" <<
  "Trand = \n"   << Trand   << "\n" << 
  "InvT = \n"    << InvT    << "\n" <<
  "InvInvT = \n" << InvInvT << std::endl;

 
  return EXIT_SUCCESS;
}
