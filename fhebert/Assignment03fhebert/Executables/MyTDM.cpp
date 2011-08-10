//
// francois hebert, jul 2011
// creates a 3x3 tensor of random O(1) datameshes and
// uses the functions I wrote to invert it
//


#include "StudentProjects/SpecClass2011/fhebert/Assignment03fhebert/InvertTensorfhebert.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/ErrorHandling/Require.hpp"

#include <cstdlib>



int main(void)
{  
  // a couple of underlying meshes
  const Mesh meshA(IPoint(MV::Size(2), 10));
  const Mesh meshB(IPoint(MV::Size(3), 3));
  
  // show that code works for both symm/asymm tensors
  const TensorStructure tsSymmRank2Dim3(3, "11");
  const TensorStructure tsAsymmRank2Dim3(3, "12");
  
  Tensor<DataMesh> tSymm(tsSymmRank2Dim3, meshA, 0.0);
  Tensor<DataMesh> tAsymm(tsAsymmRank2Dim3, meshB, 0.0);

  // set each datamesh entry to a random number
  // use a reproducible seed for debugging
  srand(0);
  for (int i=0; i<tSymm.Dim(); ++i)
    for (int j=0; j<tSymm.Dim(); ++j)
      for (int k=0; k<tSymm(0,0).Size(); ++k)
      {
        tSymm(i,j)[k] = double(rand())/RAND_MAX;
      }

  for (int i=0; i<tAsymm.Dim(); ++i)
    for (int j=0; j<tAsymm.Dim(); ++j)
      for (int k=0; k<tAsymm(0,0).Size(); ++k)
      {
        tAsymm(i,j)[k] = double(rand())/RAND_MAX;
      }

  // now invert twice
  const Tensor<DataMesh> invinvSymm = InvTensor(InvTensor(tSymm));
  const Tensor<DataMesh> invinvAsymm = InvTensor(InvTensor(tAsymm));

  // printing out TDMs is messy and not very illuminating, so
  // as an error indicator, i find the maximum difference b/w
  // this and the original tensor:
  double err = 0;
  double maxerrSymm = 0;
  for (int i=0; i<tSymm.Dim(); ++i)
    for (int j=0; j<tSymm.Dim(); ++j)
      for (int k=0; k<tSymm(0,0).Size(); ++k)
      {
        err = tSymm(i,j)[k] - invinvSymm(i,j)[k];
        if (maxerrSymm < fabs(err))
          maxerrSymm = fabs(err);
      }

  err = 0;
  double maxerrAsymm = 0;
  for (int i=0; i<tAsymm.Dim(); ++i)
    for (int j=0; j<tAsymm.Dim(); ++j)
      for (int k=0; k<tAsymm(0,0).Size(); ++k)
      {
        err = tAsymm(i,j)[k] - invinvAsymm(i,j)[k];
        if (maxerrAsymm < fabs(err))
          maxerrAsymm = fabs(err);
      }

  // running this on several meshes and seeds, i found errors typically
  // of O(e-15) and up to O(e-13), which is close to roundoff thresholds
  std::cout << "maximum difference between Tsymm and inv(inv(Tsymm)) is: " << maxerrSymm << "\n";
  std::cout << "maximum difference between Tasymm and inv(inv(Tasymm)) is: " << maxerrAsymm << "\n";

  return EXIT_SUCCESS;
}

