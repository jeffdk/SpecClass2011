#include "AddTensors.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {
  
  AddTensors::AddTensors(const std::string& opts) 
    : mResult(TensorStructure::Empty) 
  {
    OptionParser p(opts,Help());
    mA      = p.Get<std::string>("A");
    mB      = p.Get<std::string>("B");
    mOutput = p.Get<std::string>("Output");
  }


  void AddTensors::RecomputeData(const DataBoxAccess& box) const {

    const Tensor<DataMesh>& A = box.Get<Tensor<DataMesh> >(mA);
    const Tensor<DataMesh>& B = box.Get<Tensor<DataMesh> >(mB);

    REQUIRE(A.Structure()==B.Structure(),
	    "Structure Mismatch:"
	    << " A->" << A.Structure()
            << " B->" << B.Structure()
            << "\nSpecified options: "
	    << " A = " << mA << ", B = " << mB 
	    << ", Output = " << mOutput << "\n" << Help());

    mResult = A;

    Tensor<DataMesh>::iterator ita       = mResult.begin();
    Tensor<DataMesh>::const_iterator itb = B.begin();
    for(;ita!=mResult.end();++ita,++itb) *ita += *itb;
  }

}
