#include "Mesh.hpp"
#include <cstdlib>
     
int main(void) {
   //Define a MyVector with the needed extents
   const IPoint extents(MV::fill, 10,10);
   //With these as imputs, make a 10x10 mesh
   const Mesh m(extents);
   //Read out the size of the mesh
   std::cout << "mesh.Extents()="<<m.Extents()<<"\n";
   //Read out the dimensions of the mesh, should give 2
   std::cout << "mesh.Dim()="<<m.Dim()<<"\n";

   //I want to find the location of (3,4) in the mesh
   //First I define a MyVector with the point in it
   const IPoint p1(MV::fill,3,4);
   //Now I use the DataOffset function to tell me where p1 is in the mesh
   std::cout << "index of point " << p1 << "="<< m.DataOffset(p1)<<"\n";

   //Next, the 2 index corresponding to the first point in the array should be
   //(0,0). I verify by calling the place of (0,0)
   const IPoint p2(MV::fill,0,0);
   std::cout << "index of the first point " << p2 << "="<< m.DataOffset(p2)
   <<"\n";

   
return EXIT_SUCCESS;
}


