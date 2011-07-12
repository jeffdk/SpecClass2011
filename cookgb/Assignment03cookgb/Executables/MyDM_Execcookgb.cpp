#include "DataMesh.hpp"
#include <cstdlib>
     
int main(void) {
  const IPoint extents(MV::Size(3), 10);
  const Mesh m(extents);
  DataMesh a(m);

  // The potentially faster way
  //-:int aind = 0;
  //-:for(int k=0; k<extents[2]; ++k)
  //-:  for(int j=0; j<extents[1]; ++j)
  //-:    for(int i=0; i<extents[0]; ++i)
  //-:	a[aind++] = 1000*i + 100*j + 100000*k;

  // The safer SpEC way
  for(int k=0; k<extents[2]; ++k)
    for(int j=0; j<extents[1]; ++j)
      for(int i=0; i<extents[0]; ++i)
	a[m.DataOffset(IPoint(MV::fill,i,j,k))] = 1000*i + 100*j + 100000*k;

  std::cout << "assigned datamesh:"<<a<<"\n";
     
  return EXIT_SUCCESS;
}

