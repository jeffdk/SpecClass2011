#include "MatrixUtils3x3Curran.hpp"

#include "NR3RanCurran.hpp"
#include "Utils/DataMesh/Mesh.hpp"
#include "Utils/ErrorHandling/Require.hpp"

namespace Assignment03Curran {

DataMesh Determinant3x3Sym(const Tensor<DataMesh>& mat) {
    const int dim = 3;
    const TensorStructure ts(dim, "aa");
    REQUIRE(ts == mat.Structure(), "mat must be a symmetrix 3x3 tensor");

    // Compute determinant
    const DataMesh& a = mat(0,0);
    const DataMesh& b = mat(0,1);
    const DataMesh& c = mat(0,2);
    const DataMesh& d = mat(1,1);
    const DataMesh& e = mat(1,2);
    const DataMesh& f = mat(2,2);
    DataMesh det = 2.0*b*c*e + a*d*f - (a*e*e + d*c*c + f*b*b);

    return det;
}

Tensor<DataMesh> Inverse3x3Sym(const Tensor<DataMesh>& mat) {
    const int dim = 3;
    const TensorStructure ts(dim, "aa");
    REQUIRE(ts == mat.Structure(), "mat must be a symmetrix 3x3 tensor");

    // Compute determinant and use it to check for invertibility
    const DataMesh det = Determinant3x3Sym(mat);
    for (int i = 0; i < det.Size(); ++i) {
        REQUIRE(det[i] != 0.0,
                "Vanishing determinant found; tensor is not invertible");
    }

    // Allocate inverse matrix
    const Mesh mesh(mat(0,0).Extents());
    Tensor<DataMesh> inv(ts, mesh);

    const DataMesh& a = mat(0,0);
    const DataMesh& b = mat(0,1);
    const DataMesh& c = mat(0,2);
    const DataMesh& d = mat(1,1);
    const DataMesh& e = mat(1,2);
    const DataMesh& f = mat(2,2);
    inv(0,0) = (d*f - e*e) / det;
    inv(0,1) = (c*e - b*f) / det;
    inv(0,2) = (b*e - c*d) / det;
    inv(1,1) = (a*f - c*c) / det;
    inv(1,2) = (b*c - a*e) / det;
    inv(2,2) = (a*d - b*b) / det;

    return inv;
}

Tensor<DataMesh> Multiply3x3Sym(const Tensor<DataMesh>& a,
                                const Tensor<DataMesh>& b) {
    const int dim = 3;
    const TensorStructure ts(dim, "aa");
    REQUIRE(ts == a.Structure(), "a must be a symmetrix 3x3 tensor");
    REQUIRE(ts == b.Structure(), "b must be a symmetrix 3x3 tensor");
    REQUIRE(a(0,0).Extents() == b(0,0).Extents(),
            "a and b must contain DataMeshes of the same extent");

    const Mesh mesh(a(0,0).Extents());
    Tensor<DataMesh> prod(ts, mesh);

    for (int i = 0; i < dim; ++i) {
        for (int j = i; j < dim; ++j) {
            prod(i,j) = a(i,0)*b(0,j) + a(i,1)*b(1,j) + a(i,2)*b(2,j);
        }
    }

    return prod;
}

void Random3x3Sym(const int seed, Tensor<DataMesh>& mat) {
    const int dim = 3;
    NR3Ranq2 rng(seed);
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            for (int idx = 0; idx < mat(i,j).Size(); ++idx) {
                mat(i,j)[idx] = rng.NextDouble();
            }
        }
    }
}

}

