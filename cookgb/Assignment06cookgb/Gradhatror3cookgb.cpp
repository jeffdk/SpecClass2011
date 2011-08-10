#include "Gradhatror3cookgb.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {

  Gradhatror3cookgb::Gradhatror3cookgb(const std::string& opts) :
    mResult(TensorStructure::Empty) {
    OptionParser p(opts, Help());
    mOutput=p.Get<std::string>("Output");
  }

  void Gradhatror3cookgb::RecomputeData(const DataBoxAccess& box) const {
    typedef Tensor<DataMesh> TDm;

    const MyVector<DataMesh>& coords=
      box.Get<MyVector<DataMesh> >("GlobalCoords");

    DataMesh tmp = coords[0]*coords[0] + 
                   coords[1]*coords[1] + 
                   coords[2]*coords[2]; // r^2
    tmp = 1./(tmp*tmp); // 1/r^4

    TDm res(3,"a",tmp);
    res(0) = coords[0]*tmp;
    res(1) = coords[1]*tmp;
    res(2) = coords[2]*tmp;

    mResult.assign(res);
  }

}
