//
// francois hebert, jul 2011
//
// implementation of the determinant and inverse of a 3x3 TDM
//



#include <cstdlib>

#include "DataMesh.hpp"
#include "Tensor.hpp"
#include "Require.hpp"


//=========================================================
// this function calculates the determinant of a given 
// rank-2 tensor and outputs it as a rank-0 tensor
//=========================================================
Tensor<DataMesh> DetTensor( const Tensor<DataMesh> & Tin )
{
  // first check that Tin is in fact 3x3
  REQUIRE(Tin.Dim()==3, "det3x3 can only take determinant of 3x3");
  REQUIRE(Tin.Rank()==2, "det3x3 can only take rank of 3x3");

  // declare, assign determinant as a scalar TDM
  Tensor<DataMesh> Tout(3, "", Mesh(Tin(0,0).Extents()), 0.0);

  Tout()  = Tin(0,0) * ( Tin(1,1)*Tin(2,2) - Tin(2,1)*Tin(1,2) );
  Tout() -= Tin(0,1) * ( Tin(1,0)*Tin(2,2) - Tin(2,0)*Tin(1,2) );
  Tout() += Tin(0,2) * ( Tin(1,0)*Tin(2,1) - Tin(2,0)*Tin(1,1) );

  return Tout;
}


//=========================================================
// this function calculates the inverse of a 3x3 tensor
// starts by checking that the determinant is non-zero
//=========================================================
Tensor<DataMesh> InvTensor( const Tensor<DataMesh> & Tin )
{
  // first, set up calculation
  const int len = Tin(0,0).Size();
  
  Tensor<DataMesh> Tout = Tin;
  Tensor<DataMesh> det = DetTensor(Tin);

  // check for non-zero determinant
  for (int i=0; i<len; ++i)
    REQUIRE(det()[i]!=0.0, "determinant vanishes!");
      
  // then calculate new values (using mathworld.wolfram.com here)
  for (int i=0; i<len; ++i)
  {
    // for a symmetric tensor, only need these:
    Tout(0,0) = (Tin(1,1)*Tin(2,2) - Tin(2,1)*Tin(1,2)) / det();
    Tout(0,1) = (Tin(0,2)*Tin(2,1) - Tin(2,2)*Tin(0,1)) / det();
    Tout(0,2) = (Tin(0,1)*Tin(1,2) - Tin(1,1)*Tin(0,2)) / det();
    Tout(1,1) = (Tin(0,0)*Tin(2,2) - Tin(2,0)*Tin(0,2)) / det();
    Tout(1,2) = (Tin(0,2)*Tin(1,0) - Tin(1,2)*Tin(0,0)) / det();
    Tout(2,2) = (Tin(0,0)*Tin(1,1) - Tin(1,0)*Tin(0,1)) / det();

    // if not symmetric, also need:
    if (Tin.Structure() != TensorStructure(Tin.Dim(), "11"))
    {
      Tout(1,0) = (Tin(1,2)*Tin(2,0) - Tin(2,2)*Tin(1,0)) / det();
      Tout(2,0) = (Tin(1,0)*Tin(2,1) - Tin(2,0)*Tin(1,1)) / det();
      Tout(2,1) = (Tin(0,1)*Tin(2,0) - Tin(2,1)*Tin(0,0)) / det();
    }
  }

  return Tout;
}

