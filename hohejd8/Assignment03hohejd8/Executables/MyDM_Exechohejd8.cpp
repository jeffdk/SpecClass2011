#include "DataMesh.hpp"
#include <cstdlib>
 
int main(void) {
  const IPoint extents(MV::Size(3), 10);
  const Mesh m(extents);
  DataMesh a(m);

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      for(int k=0; k<10; k++){
        a[m.DataOffset(IPoint(MV::fill,i,j,k))] = //
              1000*i + 100*j + 100000*k;
      }
    }
  }

  // use this to test the accuracy of setting the values
  // for each element
  std::cout << "DataMesh a = " << a << std::endl;
 
  return EXIT_SUCCESS;
}
