#include "ComputeQ_danh.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {
  
  ComputeQ_danh::ComputeQ_danh(const std::string& opts): 
    mResult(3, "1", DataMesh::Empty) {
    OptionParser p(opts, Help()); 
    mInput  = p.Get<std::string>("Input");
    mOutput = p.Get<std::string>("Output");
  }
  
  void ComputeQ_danh::RecomputeData(const DataBoxAccess& box) const {
    const MyVector<DataMesh>& x = box.Get<MyVector<DataMesh> >("GlobalCoords");
    const Tensor<DataMesh>& v = box.Get<Tensor<DataMesh> >(mInput);
  
    ASSERT_TensorStructure(v, 3, "1");
    mResult = v;
  }

} 
