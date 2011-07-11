#include <cstdlib>
#include <iostream>

#include "Mesh.hpp"
#include "Require.hpp"
 
int main(int /*argc*/, char** /*argv*/) {
    // Create the mesh
    const IPoint extents(MV::fill, 10, 10);
    const Mesh mesh(extents);

    // Check the mesh's dimension and size
    const int expected_dim = 2;
    std::cout << "Checking that mesh dimension is " << expected_dim << "..." <<
                 std::endl;
    REQUIRE(mesh.Dim() == expected_dim, "Mesh dimension is not as expected");
    std::cout << "success!" << std::endl;

    const int expected_size = 100;
    std::cout << "Checking that mesh size is " << expected_size << "..." <<
                 std::endl;
    REQUIRE(mesh.Size() == expected_size, "Mesh size is not as expected");
    std::cout << "success!" << std::endl;
 
    // Explore 1D and 2D indices
    const IPoint p1(MV::fill, 3, 4);
    std::cout << "The 1D index of point " << p1 << " is " <<
                 mesh.DataOffset(p1) << std::endl;

    const IPoint p2(MV::fill, 0, 0);
    std::cout << "Checking that " << p2 << " is the first point..." <<
                 std::endl;
    REQUIRE(mesh.DataOffset(p2) == 0, "First point not as expected");
    std::cout << "success!" << std::endl;
 
    return EXIT_SUCCESS;
}

