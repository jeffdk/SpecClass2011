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

    const TDm& x = box.Get<TDm>("X0");
    const TDm& y = box.Get<TDm>("X1");
    const TDm& z = box.Get<TDm>("X2");

    DataMesh tmp = x()*x() + y()*y() + z()*z(); // r^2
    tmp = 1./(tmp*tmp); // 1/r^4

    TDm res(tmp.Dim(),"a");
    res(0) = x()*tmp;
    res(1) = y()*tmp;
    res(2) = z()*tmp;

    mResult.assign(res);
  }

}
