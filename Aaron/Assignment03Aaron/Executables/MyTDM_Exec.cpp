    #include "DataMesh.hpp"
    #include "Tensor.hpp"
    #include <cstdlib>
     
    int main(void) {
      TensorStructure s(3,"ab");
      // Tensor<DataMesh> t1(s); // will fail to compile
      const Mesh m(IPoint(MV::fill,2,2));
      Tensor<DataMesh> t2(s,m); // will be fine
      Tensor<DataMesh> t3(s,m, 0.0); // this initializes all DataMesh points to zero
      Tensor<DataMesh> t4(3,"ab",m, 0.0); // this is the same as before
     
      return EXIT_SUCCESS;
    }


