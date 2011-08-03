
#include "Hw6CompItemfhebert.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"


namespace ComputeItems {

  Hw6CompItemfhebert::Hw6CompItemfhebert(const std::string& opts): 
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    mOutput=p.Get<std::string>("Output");
  }
  
  void Hw6CompItemfhebert::RecomputeData(const DataBoxAccess& box) const {
  
    const MyVector<DataMesh>& Coords =
        box.Get<MyVector<DataMesh> >("GlobalCoords");

    // convert from x,y,z to r
    DataMesh RSqrd(Coords[0], 0.0);
    for (int dim=0; dim<Coords.Size(); ++dim)
    {
      RSqrd += Coords[dim]*Coords[dim];
    }
    const DataMesh R=sqrt(RSqrd);

    // give output on the same Mesh as the GlobalCoords:
    mResult.assign(Coords[0].Dim(), "a", Coords[0]);
    for (int dim=0; dim<Coords.Size(); ++dim)
    {
      mResult(dim) = Coords[dim] / (R*R*R);
    }
    
  }
}
