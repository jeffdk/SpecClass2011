//
// francois hebert, jul 2011
// simple executable with Mesh
//


#include "Utils/DataMesh/Mesh.hpp"

#include<cstdlib>


int main(void)
{
 
  // create a 10x10 mesh:
  const IPoint extents(MV::fill, 10, 10);
  const Mesh m(extents);

  // check that the size and dimension are as expected:
  // this outputs size = 100, dim = 2
  // as expected for a 10x10 array of numbers
  std::cout << "mesh.Extents() = " << m.Extents() << std::endl;
  std::cout << "mesh.Size()    = " << m.Size() << std::endl;
  std::cout << "mesh.Dim()     = " << m.Dim() << std::endl;

  // points of interest
  const IPoint p1(MV::fill, 3, 4);
  const IPoint p2(MV::fill, 0, 0);

  // this tells us that the 1D offset of p1 is 43
  // and that (0,0) is the 0th element, as i had expected
  std::cout << "index of point " << p1 << " = " << m.DataOffset(p1) << std::endl;
  std::cout << "index of point " << p2 << " = " << m.DataOffset(p2) << std::endl;

  return EXIT_SUCCESS;

}
