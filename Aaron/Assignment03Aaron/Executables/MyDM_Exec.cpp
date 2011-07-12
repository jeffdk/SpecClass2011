    #include "DataMesh.hpp"
    #include <cstdlib>
     
    int main(void) {
      const IPoint extents(MV::Size(2), 2);
      const Mesh m(extents);
      DataMesh a(m);
      std::cout << "unassigned datamesh:"<<a<<"\n";
      DataMesh b(m,2.5);
      std::cout << "datamesh set to 2.5:"<<b<<"\n";
     
      b[2]=9.1; //Third point in 2x2 matrix, recall counting starts at 0
      std::cout << "slightly changed datamesh:"<<b<<"\n";
     
      a = b+10;
      std::cout << "yet another datamesh:"<<a<<"\n";
     
      // further manipulations:
      a -= 10;
      b=sqr(a);
      a *= b;
      const DataMesh c=exp(tan(a+b));
     
      return EXIT_SUCCESS;
    }


