#include "Mesh.hpp"
#include <cstdlib>
 
int main(void) {
  const IPoint extents(MV::fill, 10,10);
  const Mesh m(extents);
  std::cout << "mesh.Dim()="<<m.Dim()<<"\n";
  std::cout << "mesh.Size()="<<m.Size()<<"\n";

  std::cout << "index of point (3,4) = " 
            << m.DataOffset(IPoint(MV::fill,3,4)) << std::endl;
  std::cout << "index of point (0,0) = " 
            << m.DataOffset(IPoint(MV::fill,0,0)) << std::endl;
 
  return EXIT_SUCCESS;
}
