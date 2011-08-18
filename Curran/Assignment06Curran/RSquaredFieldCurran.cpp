#include "RSquaredFieldCurran.hpp"

#include "Utils/DataBox/DataBoxAccess.hpp"
#include "Utils/DataMesh/Mesh.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/MiscUtils/SimpleProfiler.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {

RSquaredFieldCurran::RSquaredFieldCurran(const std::string& opts) :
    result_(TensorStructure::Empty) {
    OptionParser parser(opts, Help());
    output_name_ = parser.Get<std::string>("Output");
}

void RSquaredFieldCurran::RecomputeData(
        const DataBoxAccess& box) const {
    SimpleProfiler prof("RSquaredFieldCurran");
    typedef Tensor<DataMesh> TDm;

    // Retrieve and validate items from DataBox
    const Mesh& mesh = box.Get<Mesh>("Mesh");
    const int dim = mesh.Dim();
    const MyVector<DataMesh>& coords =
            box.Get<MyVector<DataMesh> >("GlobalCoords");
    REQUIRE(3 == dim, "Only coded in three dimensions");
    REQUIRE(coords.Size() == dim, "Dim of GlobalCoords does not match Mesh");

    // Initialize result
    if (result_.Empty() || (mesh != result_(0))) {
        result_.assign(dim, "1", mesh);
    }

    // Perform the computation
    const DataMesh r3 = pow(coords[0]*coords[0] + coords[1]*coords[1] +
                            coords[2]*coords[2], 1.5);
    for (int i = 0; i < dim; ++i) {
        result_(i) = coords[i] / r3;
    }
}

}

