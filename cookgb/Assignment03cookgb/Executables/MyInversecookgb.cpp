#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include <cstdlib>

// Define to create a symmetric tensor
//#define SYMMETRY

void MyInverse(const Tensor<DataMesh>& T, Tensor<DataMesh>& invT) {
  // Make sure the tensors are second rank
  REQUIRE(T.Rank()==2,"Inverse only for 2nd Rank Tensors");
  REQUIRE(invT.Rank()==2,"Inverse must alos be 2nd Rank Tensors");

  // Find the determinant (don't assume symmetry for generality)
  DataMesh det = T(0,0)*(T(1,1)*T(2,2) - T(2,1)*T(1,2)) -
                 T(0,1)*(T(1,0)*T(2,2) - T(2,0)*T(1,2)) +
                 T(0,2)*(T(1,0)*T(2,1) - T(2,0)*T(1,1));

  // Check to see if determinant is zero anywhere
  for(int i=0; i<det.Size(); ++i)
    REQUIRE(det[i]!=0.0,"Can't compute inverse, det=0 somewhere in the mesh");

  // Set the inverse (assume symmetry here)
  invT(0,0) = (T(1,1)*T(2,2) - T(2,1)*T(1,2))/det;
  invT(0,1) = - (T(0,1)*T(2,2) - T(2,1)*T(0,2))/det;
  invT(0,2) = (T(0,1)*T(1,2) - T(1,1)*T(0,2))/det;
  invT(1,1) = (T(0,0)*T(2,2) - T(2,0)*T(0,2))/det;
  invT(1,2) = - (T(0,0)*T(1,2) - T(1,0)*T(0,2))/det;
  invT(2,2) = (T(0,0)*T(1,1) - T(1,0)*T(0,1))/det;
  // Now deal with the possibility of no symmetry
  if(TensorStructure(T.Dim(),"11") != invT.Structure()) {
    // InvT doesn't have symmetry even if T does!
    invT(1,0) = - (T(1,0)*T(2,2) - T(2,0)*T(1,2))/det;
    invT(2,0) = (T(1,0)*T(2,1) - T(2,0)*T(1,1))/det;
    invT(2,1) = - (T(0,0)*T(2,1) - T(2,0)*T(0,1))/det;
  }
}

int main(void) {
  // define the mesh
  // const Mesh m(IPoint(MV::fill,10,10));
  const Mesh m(IPoint(MV::fill,3,3,3));

  // initialize the random numer generator
  srandom(3924);
  
#ifdef SYMMETRY
  // ASSUMES SYMMETRY
  Tensor<DataMesh> tenran(3,"aa",m);
  // Fill the tensor with random numbers(range[0->10]) at each DataMesh location
  for(int i=0; i<3; ++i)
    for(int j=i; j<3; ++j) { // symmetric so don't do extra work
      DataMesh & tm = tenran(i,j);
      const int nelems = tm.Size();
      for(int k=0; k<nelems; ++k) {
  	tm[k] = 10.0*(static_cast<double>(random()))/(RAND_MAX);
      }
    }
#else  
  // ASSUMES NO SYMMETRY
  Tensor<DataMesh> tenran(3,"ab",m);
  // Fill the tensor with random numbers(range[0->10]) at each DataMesh location
  for(int i=0; i<3; ++i)
    for(int j=0; j<3; ++j) {
      DataMesh & tm = tenran(i,j);
      const int nelems = tm.Size();
      for(int k=0; k<nelems; ++k) {
	tm[k] = 10.0*(static_cast<double>(random()))/(RAND_MAX);
      }
    }
#endif

  // Get the inverse
  Tensor<DataMesh> invten(tenran.Structure(),m);
  MyInverse(tenran,invten);

  // Contract tensor with it's inverse
  Tensor<DataMesh> testten(3,"ab",m,0.0);  // No Symmetry
  for(int i=0; i<3; ++i)
    for(int j=0; j<3; ++j)
      for(int k=0; k<3; ++k)
	testten(i,j) += tenran(i,k)*invten(k,j);

  // View the results
  std::cout << "Should be the identity matrix (to roundoff)\n"
	    << testten << std::endl;
     
  return EXIT_SUCCESS;
}

