#include "Mesh.hpp"

int main(void) {
  const IPoint extents(MV::fill, 10,10,10);
  const Mesh m(extents);
  std::cout << "mesh.Extents()="<<m.Extents()<<"\n";
  std::cout << "mesh.Size()="<<m.Size()<<"\n";
  std::cout << "mesh.Dim()="<<m.Dim()<<"\n";
  // Mesh mm=extents; // will fail to compile
}
