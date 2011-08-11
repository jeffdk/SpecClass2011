// InvertTDMBrett
//   Code for computing cofactors, doing matrix multiplication, and inverting matrices.
//   Brett Deaton
//   7.12.11

#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/TensorStructure.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/ErrorHandling/Assert.hpp"
#include "StudentProjects/SpecClass2011/BrettDeaton/Assignment03Brett/InvertTDMBrett.hpp"

// ***************************************************************************
// Return the cofactor of A_{a,b} for A 3D
DataMesh Cofactor(const Tensor<DataMesh>& A, const int a, const int b){
  ASSERT(a<3&&a>-1,"a out of range");
  ASSERT(b<3&&b>-1,"b out of range");
  int sign = (/*(a+b)%2==0*/true) ? 1 : -1;
  return sign * ( A((a+1)%3,(b+1)%3) * A((a+2)%3,(b+2)%3) -
		  A((a+1)%3,(b+2)%3) * A((a+2)%3,(b+1)%3) );
}

// ***************************************************************************
Tensor<DataMesh> MatrixMultiply(const Tensor<DataMesh>& A, const Tensor<DataMesh>& B){

  const IPoint ext(A(0,0).Extents());
  ASSERT(B(0,0).Extents()==ext,
	 "Error: TDM A & B do not have the same extents.");
  const TensorStructure EnforcedStructure(3,"aa");
  ASSERT(A.Structure()==EnforcedStructure && B.Structure()==EnforcedStructure,
	 "Error: A tensor does not meet the structure requirements for this function.");
  
  Mesh m(ext);
  const TensorStructure ProductStructure(3,"ab"); // product of symmetric matrices not symmetric
  Tensor<DataMesh> AtimesB(ProductStructure,m);
  for(int a=0;a<3;++a){
    for(int b=0;b<3;++b){
      AtimesB(a,b) =
        A(a,0) * B(0,b) +
        A(a,1) * B(1,b) +
        A(a,2) * B(2,b);
    }
  }

  return AtimesB;
}

// ***************************************************************************
// Invert Matrix
Tensor<DataMesh> InvertTDM(const Tensor<DataMesh>& A) {
  
  const IPoint ext(A(0,0).Extents());
  const TensorStructure EnforcedStructure(3,"aa");
  ASSERT(A.Structure()==EnforcedStructure,
	 "Error: Tensor A does not meet the structure requirements for this function.");
  
  
  const Mesh m(ext);
  DataMesh detA(m);
  detA =
    A(0,0)*Cofactor(A,0,0) +
    A(0,1)*Cofactor(A,0,1) +
    A(0,2)*Cofactor(A,0,2);
  DataMesh zero(m,0);
  REQUIRE(detA!=zero,"Error: Tensor A is not invertible.");
  //  std::cout << "Determinant = " << detA << "\n";
  
  Tensor<DataMesh> invA(A.Structure(),m); // inv of symmetric matrix is symmetric
  for(int a=0;a<3;++a){
    for(int b=0;b<=a;++b){
      invA(a,b) = Cofactor(A,b,a) / detA;
    }
  }
  
  return invA;
}
