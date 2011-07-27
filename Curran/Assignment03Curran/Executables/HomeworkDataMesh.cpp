#include <cstdlib>
#include <iostream>

#include "Utils/DataMesh/DataMesh.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
    // Create the DataMesh
    const IPoint extents(MV::fill, 10, 10, 10);
    const Mesh mesh(extents);
    DataMesh dm(mesh);

    for (int i = 0; i < extents[0]; ++i) {
        for (int j = 0; j < extents[1]; ++j) {
            for (int k = 0; k < extents[2]; ++k) {
                const IPoint p(MV::fill, i, j, k);
                dm[dm.DataOffset(p)] = 1000.0*i + 100.0*j + 100000.0*k;
            }
        }
    }

    std::cout << dm << std::endl;
 
    return EXIT_SUCCESS;
}

