#include "Mesh.hpp"
#include <cstdlib>

int main(void) {
  const IPoint extents(MV::fill, 10,10);
  const Mesh m(extents);
  std::cout << "mesh.Extents()="<<m.Extents()<<"\n";
  std::cout << "mesh.Size()="<<m.Size()<<"\n";
  std::cout << "mesh.Dim()="<<m.Dim()<<"\n";
  // Mesh mm=extents; // will fail to compile

  const IPoint p1(MV::fill,3,4);
  const IPoint p2(MV::fill,0,0);
  std::cout << "index of point " << p1 << "="<< m.DataOffset(p1)<<"\n";
  std::cout << "index of point " << p2 << "="<< m.DataOffset(p2)<<"\n";

  return EXIT_SUCCESS;
}
