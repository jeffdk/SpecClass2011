#include "DescriptiveName_Bohn.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/MyContainers/MyVector.hpp"

namespace ComputeItems {

  DescriptiveName::DescriptiveName(const std::string& opts) :
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    mOutput=p.Get<std::string>("Output");
  }

  //================================================================

  void DescriptiveName::RecomputeData(const DataBoxAccess& box) const {
    const MyVector<DataMesh>& coords =
      box.Get<MyVector<DataMesh> >("GlobalCoords");
    const Mesh& mesh = box.Get<Mesh>("Mesh");

    // Stores the quantity r^2, which is convenient (see the comment below)
    DataMesh rSquared(mesh, 0);
    for (int i = 0; i < coords.Size(); i++)
    {
      rSquared += sqr(coords[i]);
    }

    mResult.assign(mesh.Dim(), "1", mesh);
    // Calculuate x^i / r^3 where r^3 is r^2 * sqrt(r^2)
    for (int i = 0; i < coords.Size(); i++)
    {
      mResult(i) = coords[i] / (rSquared * sqrt(rSquared));
    }
  }

} // namespace ComputeItems

