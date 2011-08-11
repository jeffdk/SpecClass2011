#include "Utils/DataMesh/DataMesh.hpp"
#include <cstdlib>

int main(void) {
  const IPoint extents(MV::fill,10,10,10);
  const Mesh m(extents);
  DataMesh a(m);

  IPoint p(MV::Size(3));
  for(int i=0;i<a.Extents()[0];++i){
    for(int j=0;j<a.Extents()[1];++j){
      for(int k=0;k<a.Extents()[2];++k){
	p.assign(MV::fill,i,j,k);
	// std::cout << "what am I pointing to right now: " << p << "\n";
	a[m.DataOffset(p)] = 1000*i + 100*j + 100000*k;
      }
    }
  }

  std::cout << "The DataMesh you constructed: " << a << "\n";

  return EXIT_SUCCESS;
}
