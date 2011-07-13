#include "DataMesh.hpp"
#include <cstdlib>
 
int main(void) {

  // Create a DataMesh of size 10x10x10
  // Values are 1000*i + 100*j + 100000*k,
  // where (i,j,k) are the indices along each dimension

  const IPoint extents(MV::Size(3), 10);
  const Mesh m(extents);
  DataMesh a(m);
  for (int i=0; i<a.Extents()[0]; i++)
    for (int j=0; j<a.Extents()[0]; j++)
      for (int k=0; k<a.Extents()[0]; k++)
	{
	  const IPoint indices(MV::fill,i,j,k);
	  a[m.DataOffset(indices)] = 1000*i + 100*j + 10000*k;
	}
  // A test to see that it's working right
  // For point (3,4,5), you should get 53400.

  const IPoint p1(MV::fill,3,4,5);
  std::cout << "index of point " << p1 << "=" << a[a.DataOffset(p1)] << "\n";

 
  return EXIT_SUCCESS;
}
