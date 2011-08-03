#ifndef InverseSquareField_wthrowe_hpp
#define InverseSquareField_wthrowe_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include <string>

class DataMesh;

namespace ComputeItems {
  /// Computes a radial vector field with magnitude 1/r^2
  class InverseSquareField:
    public ComputeItem<Tensor<DataMesh> >,
    private InstantiateDataBoxAdder<InverseSquareField> {
  public:
    static std::string ClassID() { return "InverseSquareField"; }
    static std::string Help() {
      return
	"InverseSquareField - compute the field \\hat{r}/r^2       \n"
	"OPTIONS:                                                  \n"
	"   Output = string                                        \n"
	"REQUIRES in the DataBox:                                  \n"
	"   nothing                                                \n"
	"PRESENTS to the DataBox:                                  \n"
	"   Tensor<DataMesh>       [Output]                        ";
    }

    InverseSquareField(const std::string& opts);

    std::string Output()         const { return mOutput; }
    const result_type& GetData() const { return mResult; }
    void RecomputeData(const DataBoxAccess& box) const;

  private:
    std::string mOutput;
    mutable result_type mResult;
  };
}

#endif
