#include <cstdlib>
#include <cmath>
#include <iostream>

#include "MatrixUtils3x3Curran.hpp"
#include "DataMesh.hpp"
#include "Tensor.hpp"

bool AreEqualAbsRel(const double a, const double b,
                    const double atol, const double rtol) {
    return fabs(a - b) < atol + 0.5*(fabs(a) + fabs(b))*rtol;
}

bool AreEqualAbsRel3x3Sym(const Tensor<DataMesh>& a, const Tensor<DataMesh>& b,
                          const double atol, const double rtol) {
    const int dim = 3;
    for (int i = 0; i < dim; ++i) {
        for (int j = i; j < dim; ++j) {
            for (int idx = 0; idx < a(i,j).Size(); ++idx) {
                if (!AreEqualAbsRel(a(i,j)[idx], b(i,j)[idx], atol, rtol)) {
                    return false;
                 }
            }
        }
    }
    return true;
}

int main(int /*argc*/, char** /*argv*/) {
    using namespace Assignment03Curran;

    const int dim = 3;

    { // Single matrix with trivial inverse
    const IPoint extents(MV::fill, 1, 1, 1);
    const Mesh mesh(extents);
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

    // Print out matrices for inspection by eye
    std::cout << mat << std::endl;
    std::cout << orig2 << std::endl;
    std::cout << inv << std::endl;
    std::cout << prod << std::endl;

    // Compare mat with inv(inv(mat))
    const bool success = AreEqualAbsRel3x3Sym(mat, orig2, 1.0e-12, 1.0e-12);
    std::cout << (success ? "Success" : "Failure") << std::endl;
    }

    { // Random tensor on 10x10 mesh
    const IPoint extents(MV::fill, 10, 10);
    const Mesh mesh(extents);
    const int dim = 3;
    Tensor<DataMesh> mat(dim, "aa", mesh);
    Random3x3Sym(12345, mat);

    Tensor<DataMesh> inv = Inverse3x3Sym(mat);
    Tensor<DataMesh> invinv = Inverse3x3Sym(inv);

    // Compare mat with inv(inv(mat))
    const bool success = AreEqualAbsRel3x3Sym(mat, invinv, 1.0e-12, 1.0e-12);
    std::cout << (success ? "Success" : "Failure") << std::endl;
    }

    { // Random tensor on 3x3x3 mesh
    const IPoint extents(MV::fill, 3, 3, 3);
    const Mesh mesh(extents);
    const int dim = 3;
    Tensor<DataMesh> mat(dim, "aa", mesh);
    Random3x3Sym(67890, mat);

    Tensor<DataMesh> inv = Inverse3x3Sym(mat);
    Tensor<DataMesh> invinv = Inverse3x3Sym(inv);

    // Compare mat with inv(inv(mat))
    const bool success = AreEqualAbsRel3x3Sym(mat, invinv, 1.0e-12, 1.0e-12);
    std::cout << (success ? "Success" : "Failure") << std::endl;
    }

    return EXIT_SUCCESS;
}

