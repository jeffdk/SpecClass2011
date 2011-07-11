#include "TensorInversewthrowe.hpp"
#include "DataMeshNorms.hpp"
#include "ComputeInverse.hpp"
#include "ComputeDeterminant.hpp"

#include <iostream>
#include <cstdlib>

double rand_double() {
  return (static_cast<double>(random())) / RAND_MAX;
}

double LinfNormDiff(const Tensor<DataMesh>& t1, const Tensor<DataMesh>& t2) {
  double norm = 0;
  for(TensorIter it(t1);it;++it) {
    double compnorm = LinfNormDiff(t1[it], t2[it]);
    if(norm < compnorm) norm = compnorm;
  }
  return norm;
}

void TestTensor(const Mesh& m) {
  Tensor<DataMesh> t(3, "11", m);
  for(TensorIter it(t);it;++it) {
    for(int i=0;i<t[it].Size();i++) {
      t[it][i] = rand_double();
    }
  }

  Tensor<DataMesh> inv(3, "11", m);
  Tensor<DataMesh> inv2(3, "11", m);
  TensorInverse(t, inv);
  TensorInverse(inv, inv2);

  double error = LinfNormDiff(t, inv2);

  DataMesh detSpec(m);
  Tensor<DataMesh> invSpec(3, "11", m);
  ComputeDeterminant(t, detSpec);
  ComputeInverse(t, detSpec, invSpec);
  double errorSpec = LinfNormDiff(inv, invSpec);
  std::cout << m << "\n"
	    << "Max error of double inverse: " << error << "\n"
	    << "Max error of inverse:        " << errorSpec << std::endl;
}

int main(void) {
  srandom(651293);

  TestTensor(Mesh(IPoint(MV::fill, 3, 3, 3)));
  TestTensor(Mesh(IPoint(MV::fill, 10, 10)));

  return EXIT_SUCCESS;
}
