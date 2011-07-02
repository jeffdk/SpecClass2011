#include "Mesh.hpp"

int main(void) {
  IPoint extents(MV::fill, 10,10);
  Mesh m(extents);
  std::cout << "mesh="<<m<<"\n";

  // Mesh mm=extents; // will fail to compile

  Mesh m2(IPoint(MV::fill,10,10,10));
  const IPoint p1(MV::fill,6,8,1);
  const IPoint p2(MV::fill,0,0,0);
  std::cout << "index of point " << p1 << "="<< m2.DataOffset(p1)<<"\n";
  std::cout << "index of point " << p2 << "="<< m2.DataOffset(p2)<<"\n";
  std::cout << "dimension of mesh="<<m2.Dim()<<"\n";
  std::cout << "size of mesh="<<m2.Size()<<"\n";

}
