//This function will compute the inverse of a 3x3 tensor data mesh
//I will use a standard method involving computing the cofactors

#include "DataMesh.hpp"
#include "Tensor.hpp"
#include <cstdlib>

#include "MyMatrixInverse.hpp"
 
Tensor<DataMesh> invert(const Tensor<DataMesh>& t, const Mesh& m) {
  //I want to invert t. 

  //I make a scalar data mesh to hold the determinant
  Tensor<DataMesh> det(3,"",m,0.0);

  //A tensor to hold the inverse
  Tensor<DataMesh> inverse(3,"ab",m,0.0);

  //The total size of the mesh
  int length = m.Size();

  //I first define the cofactors, as scalar data meshes
  Tensor<DataMesh> A(3,"",m,0.0);
  Tensor<DataMesh> B(3,"",m,0.0);
  Tensor<DataMesh> C(3,"",m,0.0);
  Tensor<DataMesh> D(3,"",m,0.0);
  Tensor<DataMesh> E(3,"",m,0.0);
  Tensor<DataMesh> F(3,"",m,0.0);
  Tensor<DataMesh> G(3,"",m,0.0);
  Tensor<DataMesh> H(3,"",m,0.0);
  Tensor<DataMesh> K(3,"",m,0.0);

  //Next I compute the determinant
  //I need the first three cofactors
  A() += ( t(1,1)*t(2,2) ) - ( t(1,2)*t(2,1) );
  B() += ( t(1,2)*t(2,0) ) - ( t(1,0)*t(2,2) );
  C() += ( t(1,0)*t(2,1) ) - ( t(1,1)*t(2,0) );

  //Now the standard definition for determinant
  det() += t(0,0)*A()+ t(0,1)*B() + t(0,2)* C();

  //These helped me debug:
  //std::cout << "Cofactor A:" << A() << "\n";
  //std::cout << "Determinant of matrix t:" << det() << "\n";

  //Now I must check that the determinant is nonzero
  //To do this I will run through the data mesh in det and check for zeros

  //Initialize new variable that counts the zeros
  int zeros = 0;

  //Run through det seeking the zeros
  for (int i=0; i< length; i++)
  {
    if(det()[i] == 0.0) zeros++;
  } 

  //Require that there be no zeros in determinant
  REQUIRE(zeros == 0, "Error: Matrix is not invertible.\n");
 
  //With the test passed, I calculate the rest of the cofactors
  D() += ( t(0,2)*t(2,1) ) - ( t(0,1)*t(2,2) );
  E() += ( t(0,0)*t(2,2) ) - ( t(0,2)*t(2,0) );
  F() += ( t(0,1)*t(2,0) ) - ( t(0,0)*t(2,1) );
  G() += ( t(0,1)*t(1,2) ) - ( t(0,2)*t(1,1) );
  H() += ( t(0,2)*t(1,0) ) - ( t(0,0)*t(1,2) );
  K() += ( t(0,0)*t(1,1) ) - ( t(0,1)*t(1,0) );

  //Now I can fill the values of the inverse matrix
  //Of course I could make this more memory efficient by not using cofactors D-K
  inverse(0,0) += A()/det();
  inverse(0,1) += D()/det();
  inverse(0,2) += G()/det();  
  inverse(1,0) += B()/det();
  inverse(1,1) += E()/det();
  inverse(1,2) += H()/det();
  inverse(2,0) += C()/det();
  inverse(2,1) += F()/det();
  inverse(2,2) += K()/det();

return inverse;
}
