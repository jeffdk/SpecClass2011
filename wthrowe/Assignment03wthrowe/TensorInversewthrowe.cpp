#include "TensorInversewthrowe.hpp"
#include "Assert.hpp"

void TensorInverse(const Tensor<DataMesh>& t, Tensor<DataMesh>& inv) {
  ASSERT(t.Rank() == 2, "Not a matrix");
  ASSERT(t.Dim() == 3, "Not 3D");
  ASSERT(t.Structure() == inv.Structure(),
	 "Tensors have different structures");
  DataMesh det = t(0,0);
  TensorDeterminant(t, det);

  for(int i=0;i<det.Size();i++) {
    ASSERT(det[i] != 0, "Singular matrix");
  }

  for(TensorIter it(t);it;++it) {
    IPoint ind = t.Structure().Indices(it.Index());
    inv[it] = (t((ind[1]+1)%3,(ind[0]+1)%3) * t((ind[1]+2)%3,(ind[0]+2)%3)
	       - t((ind[1]+1)%3,(ind[0]+2)%3) * t((ind[1]+2)%3,(ind[0]+1)%3))
      / det;
  }
}

void TensorDeterminant(const Tensor<DataMesh>& t, DataMesh& det) {
  ASSERT(t.Rank() == 2, "Not a matrix");
  ASSERT(t.Dim() == 3, "Not 3D");
  det
    = t(0,0) * (t(1,1)*t(2,2) - t(1,2)*t(2,1))
    + t(0,1) * (t(1,2)*t(2,0) - t(1,0)*t(2,2))
    + t(0,2) * (t(1,0)*t(2,1) - t(1,1)*t(2,0));
}
