#include <cstdlib>
#include <iostream>

#include "DataMesh.hpp"
#include "Tensor.hpp"
#include "MatrixUtils3x3Curran.hpp"

int main(int /*argc*/, char** /*argv*/) {
    using namespace Assignment03Curran;

    { // First block
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
    Tensor<DataMesh> orig2 = Inverse3x3Sym(inv);
    Tensor<DataMesh> prod = Multiply3x3Sym(mat, inv);

    std::cout << mat << std::endl;
    std::cout << orig2 << std::endl;
    std::cout << inv << std::endl;
    std::cout << prod << std::endl;
    } // First block

    { // Second block
    const IPoint extents(MV::fill, 10, 10);
    const Mesh mesh(extents);
    const int dim = 3;
    Tensor<DataMesh> mat(dim, "aa", mesh);
    Random3x3Sym(12345, mat);

    Tensor<DataMesh> inv = Inverse3x3Sym(mat);
    Tensor<DataMesh> orig2 = Inverse3x3Sym(inv);
    Tensor<DataMesh> prod = Multiply3x3Sym(mat, inv);

    std::cout << mat << std::endl;
    std::cout << orig2 << std::endl;
    std::cout << inv << std::endl;
    std::cout << prod << std::endl;
    } // Second block

    { // Third block
    const IPoint extents(MV::fill, 3, 3, 3);
    const Mesh mesh(extents);
    const int dim = 3;
    Tensor<DataMesh> mat(dim, "aa", mesh);
    Random3x3Sym(67890, mat);

    Tensor<DataMesh> inv = Inverse3x3Sym(mat);
    Tensor<DataMesh> orig2 = Inverse3x3Sym(inv);
    Tensor<DataMesh> prod = Multiply3x3Sym(mat, inv);

    std::cout << mat << std::endl;
    std::cout << orig2 << std::endl;
    std::cout << inv << std::endl;
    std::cout << prod << std::endl;
    } // Third block

    return EXIT_SUCCESS;
}

