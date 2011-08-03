
#include "Hw6CompItemfhebert.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"


namespace ComputeItems {

  using std::string;

  Hw6CompItemfhebert::Hw6CompItemfhebert(const string& opts): 
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    mOutput=p.Get<string>("Output");
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

    // give output on the same Mesh as the GlobalCoords:
    mResult.assign(Coords[0].Dim(), "a", Coords[0]);

    for (int dim=0; dim<Coords.Size(); ++dim)
    {
      mResult(dim) = Coords[dim] / pow(RSqrd[dim], 3./2.);
    }
    
  }
}
