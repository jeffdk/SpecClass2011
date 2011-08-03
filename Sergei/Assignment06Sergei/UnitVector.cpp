// ComputeItems/UnitVector.cpp
 
#include "UnitVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/ErrorHandling/Require.hpp"
namespace ComputeItems {
 
  using std::string;
 
  UnitVectorR::UnitVectorR(const string& opts): 
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    
    mOutput=p.Get<string>("Output");
  }
 
  void UnitVectorR::RecomputeData(const DataBoxAccess& box) const {
    typedef Tensor<DataMesh> TDm;
    
    //Get the global coordinates from the DataBox
    const MyVector<DataMesh>& coords=box.Get<MyVector<DataMesh> >("GlobalCoords");
    

    const Mesh m (coords[0].Extents());
    //Will hold the answer
    TDm answer(3,"a",m,0.0);
    //Holds the norm of the radius vector
    DataMesh r(m,0.0);
    r = sqrt(coords[0]*coords[0]+coords[1]*coords[1]+coords[2]*coords[2]);
    
    //Check that we do not divide by 0!
    for(int i=0;i<r.Size();i++){
      
      REQUIRE(r[i]!=0,"|r|=0, can't renormalize");
    }
    answer(0) = coords[0]/(r*r*r);
    answer(1) = coords[1]/(r*r*r);
    answer(2) = coords[2]/(r*r*r);
    
    //Assign the result to the variable that should have it!
    mResult.assign(answer);
    
    
  }
 
}
