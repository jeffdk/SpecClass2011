#include "DataMesh.hpp"
#include <cstdlib>
 
int main(void) {
  //I define a vector with the dimensions, 10x10x10
  const IPoint extents(MV::Size(3), 10);
  //I make a 10x10x10 mesh with the Mesh class
  const Mesh m(extents);
  //I make an unassigned data mesh
  DataMesh a(m);

  //My goal is to fill this mesh (i,j,k) according to
  //1000*i+100*j+100000*k
  //Note index in 1D array is given by (k*100+j*10+i).
  //This is because the last index is like a row index, and here the array is
  //10x10x10.
  
  int place = 0;

  for (int i=0; i<10; i++)
  {
    for (int j=0; j<10; j++)
    {
      for (int k=0; k<10; k++)
      {
      place= k*100+j*10+i;  //Tells me where in the flattened list I am
      a[place] = 1000*i+100*j+100000*k;  //Sets the data mesh value
      }
    }
  }

  //To test I note that for (1,2,3) I'm at place = 321
  //So a[321]= 301200 = k0ij00 is predicted.
  std::cout << "value of mesh at a[321]:"<<a[321]<<"\n";
 
  
  return EXIT_SUCCESS;
}
