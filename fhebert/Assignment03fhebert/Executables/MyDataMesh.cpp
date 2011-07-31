//
// francois hebert, jul 2011
// simple executable with DataMesh
//


#include "Utils/DataMesh/DataMesh.hpp"

#include<cstdlib>


int main(void)
{
  int i,j,k,l;
  IPoint ip;

  // underlying mesh
  const int size = 10;
  const IPoint extents(MV::Size(3), size);
  const Mesh m(extents);
 
  // create and assign values to the datamesh
  DataMesh x(m);
  for (i=0; i<size; ++i)
    for (j=0; j<size; ++j)
      for (k=0; k<size; ++k)
      {
        l = x.DataOffset(IPoint(MV::fill, i,j,k));
        x[l] = 1000*i + 100*j + 100000*k;
      }

  // TO CHECK ASSIGNED VALUES:
  // uncomment this line. NB: this is kind of messy in your terminal.
  //std::cout << x << std::endl;

  return EXIT_SUCCESS;
}
