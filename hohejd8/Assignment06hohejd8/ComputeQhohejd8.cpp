#include "StudentProjects/SpecClass2011/hohejd8/Assignment06hohejd8/ComputeQhohejd8.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {
 
  using std::string;
 
  ComputeQhohejd8::ComputeQhohejd8(const string& opts): 
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    mOutput=p.Get<string>("Output");
  }
 
  void ComputeQhohejd8::RecomputeData(const DataBoxAccess& box) const {
    //retrieves the necessary data
    const MyVector<DataMesh>& coords=box.Get<MyVector<DataMesh> >("GlobalCoords");

    const Mesh& mesh = coords[0];
    DataMesh radius(mesh, 0.0);

    //compute |coords|
    for(int i=0; i<coords.Size(); ++i){
      radius += coords[i]*coords[i];
    }

    radius = sqrt(radius);    

    //compute Q
    for(int i=0; i<coords.Size(); ++i){
      mResult(i) = coords[i]/(radius*radius*radius);
    }

  }
 
}
