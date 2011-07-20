#include "DataMesh.hpp"
#include "Tensor.hpp"
#include <cstdlib>
#include <time.h>
#include "InvertTensorBohn.hpp"

int main(void) {
  // Random number seed
  const int seed = time(NULL);
  std::cout << "Random Number Seed is: " << seed << "\n";
  srand(seed);

  const Mesh mDim2Side3(IPoint(MV::Size(2), 3));
  const Mesh mDim2Side10(IPoint(MV::Size(2), 10));

  TensorStructure sSymmRank2Dim3(3,"aa");
  TensorStructure sRank2Dim3(3, "ab");

  //Don't need to initalize here, it's happening just below
  Tensor<DataMesh> tSymm(sSymmRank2Dim3, mDim2Side3);
  Tensor<DataMesh> t(sRank2Dim3, mDim2Side10);

  // Randomize Matrices
  for (int i = 0; i < tSymm(0, 0).Size(); i++)
    for (int j = 0; j < tSymm.Dim(); j++)
      for (int k = 0; k < tSymm.Dim(); k++)
        tSymm(j, k)[i] = (rand() % 1000) / 10.0;

  for (int i = 0; i < t(0, 0).Size(); i++)
    for (int j = 0; j < t.Dim(); j++)
      for (int k = 0; k < t.Dim(); k++)
        t(j, k)[i] = (rand() % 1000) / 10.0;

  // Invert twice.  I don't want to store the inverse for now
  const Tensor<DataMesh> tSymmCheck = InvertTensor(InvertTensor(tSymm));
  const Tensor<DataMesh> tCheck = InvertTensor(InvertTensor(t));

  int errors = 0;
  errors += CompareTensors(tSymm, tSymmCheck);
  errors += CompareTensors(t, tCheck);

  std::cout << "Number of errors is: " << errors << "\n";
  return errors;
}
