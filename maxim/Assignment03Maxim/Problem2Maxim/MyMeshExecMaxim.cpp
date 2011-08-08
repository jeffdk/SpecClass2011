#include "Utils/DataMesh/Mesh.hpp"
#include <cstdlib>
 
using namespace std;

int main(void) {
  const IPoint extents(MV::fill, 10,10);
  const Mesh m(extents);
  cout << "mesh.Extents()="<<m.Extents() << endl;
  cout << "mesh.Size()="<<m.Size() << endl;
  cout << "mesh.Dim()="<<m.Dim() << endl;
 
  const IPoint p1(MV::fill,3,4);
  const IPoint p2(MV::fill,0,0);
  const IPoint p3(MV::fill,9,9);

  cout << "index of point\t\t\t" << p1 << "="<< m.DataOffset(p1) << endl;
  cout << "First point of the array\t" << p2 << "="<< m.DataOffset(p2) << endl;
  cout << "Last point of the array\t\t" << p3 << "="<< m.DataOffset(p3) << endl;
  return EXIT_SUCCESS;
}
