#include "Gradhatror2cookgb.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {

  Gradhatror2cookgb::Gradhatror2cookgb(const std::string& opts) :
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    mOutput=p.Get<std::string>("Output");
  }

  void Gradhatror2cookgb::RecomputeData(const DataBoxAccess& box) const {
    typedef Tensor<DataMesh> TDm;

    const MyVector<DataMesh>& coords=
      box.Get<MyVector<DataMesh> >("GlobalCoords");

    DataMesh tmp = sqrt(coords[0]*coords[0] + 
			coords[1]*coords[1] + 
			coords[2]*coords[2]); // r
    tmp = 1./(tmp*tmp*tmp); // 1/r^3

    TDm res(tmp.Dim(),"a",tmp);
    res(0) = coords[0]*tmp;
    res(1) = coords[1]*tmp;
    res(2) = coords[2]*tmp;

    mResult.assign(res);
  }

}
