#include <cstdlib>
#include <iostream>

#include "Utils/DataMesh/DataMesh.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
    const IPoint extents(MV::Size(2), 2);
    const Mesh m(extents);
    DataMesh a(m);
    std::cout << "unassigned datamesh:" << a << std::endl;
    DataMesh b(m, 2.5);
    std::cout << "datamesh set to 2.5:" << b << std::endl;
 
    b[2] = 9.1;
    std::cout << "slightly changed datamesh:" << b << std::endl;
 
    a = b + 10;
    std::cout << "yet another datamesh:" << a << std::endl;
 
    // further manipulations:
    a -= 10;
    b = sqr(a);
    a *= b;
    const DataMesh c = exp(tan(a + b));
 
    return EXIT_SUCCESS;
}

