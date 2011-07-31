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
  // points and dimensions of the underlying mesh
  // change this for part(c) of the hw assignment
  const int points = 5;
  const int spatialdims = 3;

  // don't change this lightly!
  // InvTensor() currently needs this = 3.
  const int tensordims = 3;

  // the mesh:
  const IPoint ip(MV::Size(spatialdims), points);
  const Mesh m(ip);

  Tensor<DataMesh> t(tensordims, "ab", m, 0.0);

  // set each datamesh entry to a random number
  // use a reproducible seed for debugging
  srand(0);
  int meshpoints = pow(points,spatialdims);
  for (int i=0; i<tensordims; ++i)
    for (int j=0; j<tensordims; ++j)
      for (int k=0; k<meshpoints; ++k)
      {
        t(i,j)[k] = double(rand())/RAND_MAX;
      }
 
  // now invert twice
  Tensor<DataMesh> invinv = InvTensor(InvTensor(t));

  // printing out TDMs is messy and not very illuminating, so
  // as an error indicator, i find the maximum difference b/w
  // this and the original tensor:
  double err, maxerr = 0;
  for (int i=0; i<tensordims; ++i)
    for (int j=0; j<tensordims; ++j)
      for (int k=0; k<spatialdims*points; ++k)
      {
        err = t(i,j)[k] - invinv(i,j)[k];
        if (maxerr < fabs(err))
          maxerr = fabs(err);
      }

  // running this on several meshes and seeds, i found errors typically
  // of O(e-15) and up to O(e-13), which is close to roundoff thresholds
  std::cout << "maximum difference between T and inv(inv(T)) is: " << maxerr << "\n";

  return EXIT_SUCCESS;
}

