#include "RaiseFirstIndex.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {
  
  RaiseFirstIndex::RaiseFirstIndex(const std::string& opts) 
    : mResult(TensorStructure::Empty) 
  {
    OptionParser p(opts,Help());
    mInvMetric = p.Get<std::string>("InvMetric");
    mInput     = p.Get<std::string>("Input");
    mOutput    = p.Get<std::string>("Output");
  }


  void RaiseFirstIndex::RecomputeData(const DataBoxAccess& box) const {

    const Tensor<DataMesh>& Input     = box.Get<Tensor<DataMesh> >(mInput);
    const Tensor<DataMesh>& InvMetric = box.Get<Tensor<DataMesh> >(mInvMetric);

    const int Dim = Input.Dim();

    // Sanity checks
    REQUIRE(Input.Dim()==InvMetric.Dim(),"Dimension mismatch");
    REQUIRE(Input.Rank()==2,"Implemented only for Rank 2");
    REQUIRE_TensorStructure(InvMetric,2,"11");

    mResult.assign(Dim,"12",InvMetric(0,0),0.0);

    for(int i=0;i<Dim;++i) {
      for(int j=0;j<Dim;++j) {
	for(int k=0;k<Dim;++k) {
	  mResult(i,j) += InvMetric(i,k)*Input(k,j);
	}
      }
    }
  }

}
