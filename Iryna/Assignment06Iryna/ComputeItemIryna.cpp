#include "ComputeItemIryna.hpp"                                                           
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {

  using std::string;                                       

  ComputeItemIryna::ComputeItemIryna(const string& opts):     
    mResult(TensorStructure::Empty) {                     
    OptionParser p(opts, Help());                         
    mOutput=p.Get<string>("Output");
  }
  
  void ComputeItemIryna::RecomputeData(const DataBoxAccess& box) const {
     const MyVector<DataMesh>& coords=
                         box.Get<MyVector<DataMesh> >("GlobalCoords");
     const Mesh mesh = box.Get<Mesh>("Mesh");

     DataMesh r_sq(mesh, 0.0);   
     for(int i = 0; i < coords.Size(); i++){
        r_sq += sqr(coords[i]); 
     } 
     mResult.assign(mesh.Dim(), "1", mesh);  
     for(int i = 0; i < coords.Size(); i++){
        mResult(i) = coords[i] / (r_sq * sqrt(r_sq));
     }     
  }
}
