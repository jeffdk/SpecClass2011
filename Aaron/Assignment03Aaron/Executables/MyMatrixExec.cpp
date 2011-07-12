//This executable will test my inverse function. I will compute the inverse of a 
//3x3 tensor data mesh

#include <iostream>
#include <cstdlib>
#include "DataMesh.hpp"
#include "Tensor.hpp"

#include "MyMatrixInverse.hpp"
 
int main(void) {
  //My base mesh
  const Mesh m(IPoint(MV::fill,5,5));
  //Unit Data Mesh for manipulating values of tensor
  const DataMesh u(m,1.0); 
  
  //My tensor to be inverted
  Tensor<DataMesh> t(3,"ab",m,0.0);

  //Initializing values of t using u
  //This is of course a crude way to initialize the data, and I could do something
  //more sophisticated.
  t(0,0) += 1.0*u;
  t(0,1) += 5.0*u;
  t(0,2) += 7.0*u;
  t(1,0) += 2.5*u;
  t(1,1) += 6.0*u;
  t(1,2) += 1.0*u;
  t(2,0) += 4.0*u;
  t(2,1) += 2.0*u;
  t(2,2) += 3.0*u;
  
  //I now call the function invert(t,m)
  Tensor<DataMesh> result = invert(t,m);
 
  //Some output
  std::cout << "The value of inverse(1,1) is:" << result(1,1) << "\n";

  //I now repeat the operation to get the tensor back
  Tensor<DataMesh> t1 = invert(result,m);

  //Some output
  std::cout << "The value of t(1,1) is:" << t1(1,1) << "\n";

  //Ideally I get the original value in all the entries of the mesh.
  //I do get that. Also, my inverse matches Mathematica's.

return EXIT_SUCCESS;
}
