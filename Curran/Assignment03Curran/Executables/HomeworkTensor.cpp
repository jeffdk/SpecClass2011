#include <cstdlib>
#include <iostream>

#include "DataMesh.hpp"
#include "Tensor.hpp"
#include "MatrixUtils3x3Curran.hpp"

int main(int /*argc*/, char** /*argv*/) {
    using namespace Assignment03Curran;
    const IPoint extents(MV::fill, 1, 1, 1);
    const Mesh mesh(extents);
    const int dim = 3;
    Tensor<DataMesh> mat(dim, "aa", mesh);
    mat(0,0) = 2.0;
    mat(0,1) = 0.0;
    mat(0,2) = 0.0;
    mat(1,1) = 2.0;
    mat(1,2) = 0.0;
    mat(2,2) = 2.0;

    Tensor<DataMesh> inv = Inverse3x3Sym(mat);
    Tensor<DataMesh> prod = Multiply3x3Sym(mat, inv);

    std::cout << mat << std::endl;
    std::cout << inv << std::endl;
    std::cout << prod << std::endl;

    return EXIT_SUCCESS;
}

