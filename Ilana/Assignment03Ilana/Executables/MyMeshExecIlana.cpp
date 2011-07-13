#include "Mesh.hpp"
#include <cstdlib>
 
int main(void) {
  //create a 10 by 10 grid
  const IPoint extents(MV::fill, 10,10);
  const Mesh m(extents);
  std::cout << "mesh.Extents()="<<m.Extents()<<"\n";
  std::cout << "mesh.Size()="<<m.Size()<<"\n";
  std::cout << "mesh.Dim()="<<m.Dim()<<"\n";
  // Mesh mm=extents; // will fail to compile
 
  //location of point with indices (3,4) in 1D representation of array
  const IPoint p1(MV::fill,3,4);
  //location of first point in array
  const IPoint p2(MV::fill,0,0);
  std::cout << "index of point " << p1 << "="<< m.DataOffset(p1)<<"\n";
  std::cout << "index of first point " << p2 << "="<< m.DataOffset(p2)<<"\n";
 
  return EXIT_SUCCESS;
}
