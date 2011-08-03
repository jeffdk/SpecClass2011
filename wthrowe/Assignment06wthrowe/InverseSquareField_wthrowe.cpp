#include "InverseSquareField_wthrowe.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/MyContainers/MyVector.hpp"

namespace ComputeItems {

  InverseSquareField::InverseSquareField(const std::string& opts) :
    mResult(TensorStructure::Empty) {
    OptionParser p(opts);
    mOutput = p.Get<std::string>("Output");
  }

  void InverseSquareField::RecomputeData(const DataBoxAccess& box) const {
    const MyVector<DataMesh>& coords =
      box.Get<MyVector<DataMesh> >("GlobalCoords");
    const Mesh mesh = box.Get<Mesh>("Mesh");
    DataMesh r2(mesh, 0);
    for(int i=0;i<coords.Size();i++) {
      r2 += sqr(coords[i]);
    }
    mResult.assign(mesh.Dim(), "1", mesh);
    for(int i=0;i<coords.Size();i++) {
      mResult(i) = coords[i] / (r2*sqrt(r2));
    }
  }
}
