#ifndef RaiseFirstIndex_hpp
#define RaiseFirstIndex_hpp

#include <string>
#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

namespace ComputeItems {

  /// Raises 1st index of a rank-2 Tensor<DataMesh>
  class RaiseFirstIndex : public ComputeItem<Tensor<DataMesh> >,
		     private InstantiateDataBoxAdder<RaiseFirstIndex> {
  public: 
    static std::string ClassID() { return "RaiseFirstIndex"; }
    static std::string Help() { 
      return ClassID() +                                                  "\n"
        "Raises 1st index of a rank 2 Tensor<DataMesh>.                    \n"
	"   T^i_j = g^{ik} T_kj                                            \n"
        "OPTIONS:                                                          \n"
        "   Input       = string; # T_{kj}                                 \n"
        "   Output      = string; # T^i_j                                  \n"
	"   InvMetric   = string; # g^{ik}                                 \n"
  	"REQUIRES in DataBox:                                              \n"
        "   Tensor<DataMesh>     [Input,InvMetric]                         \n"
        "PRESENTS to the DataBox                                           \n"
        "   Tensor<DataMesh>     [Output]                                  \n"
	;
    };
  public:
    RaiseFirstIndex(const std::string& opts);
    std::string Output()         const {return mOutput;}
    const result_type& GetData() const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mInput,mInvMetric,mOutput;
    mutable result_type mResult;
  };

} // End of namespace ComputeItems
#endif // RaiseFirstIndex_hpp
