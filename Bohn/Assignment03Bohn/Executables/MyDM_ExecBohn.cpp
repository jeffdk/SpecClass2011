#include "DataMesh.hpp"
#include <cstdlib>

int main(void) {
  const IPoint extents(MV::Size(3), 10);
  const Mesh m(extents);
  DataMesh thisDataMesh(m);

  //Construct DataMesh for (i,j,k) is set to 1000*i+100*j+100000*k
  for (int i = 0; i < thisDataMesh.Extents()[0]; i++)
    for (int j = 0; j < thisDataMesh.Extents()[1]; j++)
      for (int k = 0; k < thisDataMesh.Extents()[2]; k++)
      {
        const IPoint loc(MV::fill, i, j, k);
        thisDataMesh[thisDataMesh.DataOffset(loc)] = 1000 * i + 100 * j
                                                     + 100000 * k;
      }

  //std::cout << "data of datamesh: " << thisDataMesh << "\n";

  return EXIT_SUCCESS;
}


