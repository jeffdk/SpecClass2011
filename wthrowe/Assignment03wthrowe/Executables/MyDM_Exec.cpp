#include "DataMesh.hpp"
#include <cstdlib>

int main(void) {
  const IPoint extents(MV::Size(3), 10);
  const Mesh m(extents);
  DataMesh a(m);
  for(int k=0;k<10;k++) {
    for(int j=0;j<10;j++) {
      for(int i=0;i<10;i++) {
	a[a.DataOffset(IPoint(MV::fill, i, j, k))] = 1000*i + 100*j + 100000*k;
      }
    }
  }
  std::cout << a << "\n";

  return EXIT_SUCCESS;
}
