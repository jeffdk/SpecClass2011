#include "Utils/DataMesh/DataMesh.hpp"
#include <cstdlib>
 
using namespace std;

int main(void) {
  const int I = 10, J = 10, K = 10; // dimensions for a IxJxK mesh
  const IPoint extents(MV::fill, I, J, K);
  const Mesh m(extents);
  DataMesh a(m);

  int ai = 0; // 1-D index of the mesh going from 0 to I*J*K-1
  for(int k = 0; k < K; k++)
  	for(int j = 0; j < J; j++)
		for(int i = 0; i < I; i++, ai++)
			a[ai] = 1000*i + 100*j + 100000*k;

  cout << "Data mesh "<< I << "x" << J << ":" << a << endl;

  return EXIT_SUCCESS;
}
