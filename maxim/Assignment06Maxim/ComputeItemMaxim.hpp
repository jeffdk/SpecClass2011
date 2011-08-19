#ifndef ComputeItemMaxim_hpp
#define ComputeItemMaxim_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

namespace ComputeItems {
  /// Computes
  class ComputeItemMaxim: public ComputeItem<Tensor<DataMesh> >,
						  private InstantiateDataBoxAdder<ComputeItemMaxim> {
  public: 
    static std::string ClassID() { return "ComputeItemMaxim"; }
    static std::string Help() { 
      return 
	"ComputeItemMaxim                                            \n"
	"Compute formula hat{r}^i/r^2					             \n"
	"OPTIONS:                                                    \n"
	"   Output   = string                                        \n"
	"PRESENTS to the DataBox                                     \n"
	"  Tensor<DataMesh>              [Output]                      ";
    };
  public:
    ComputeItemMaxim(const std::string& opts);
  public:
    std::string Output()         const {return mOutput;}
    const result_type& GetData() const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mOutput;
    mutable Tensor<DataMesh> mResult; 
  };
}
#endif
