#include "Utils/DataMesh/Mesh.hpp"
#include <cstdlib>

int main(void) {
  const IPoint extents(MV::fill, 10,10);
  const Mesh m(extents);
  std::cout << "mesh.Extents()="<<m.Extents()<<", expecting 10,10\n";
  std::cout << "mesh.Size()="<<m.Size()<<", expecting 100\n";
  std::cout << "mesh.Dim()="<<m.Dim()<<", expecting 2\n";
  // Mesh mm=extents; // will fail to compile

  const IPoint p1(MV::fill,3,4);
  const IPoint p0(MV::fill,0,0);
  // Where is point 3,4?
  std::cout << "index of point " << p1 << "="<< m.DataOffset(p1)<<"\n";
  //Where is point 0,0, the first point?  I'm guessing 0
  std::cout << "index of first point " << p0 << "="<< m.DataOffset(p0)<<"\n";

  return EXIT_SUCCESS;
}


