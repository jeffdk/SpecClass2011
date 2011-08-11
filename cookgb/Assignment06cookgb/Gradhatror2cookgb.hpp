#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/DataBox/InstantiateDataBoxAdder.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

#include <string>

namespace ComputeItems {

  class Gradhatror2cookgb: public ComputeItem<Tensor<DataMesh> >,
			   private InstantiateDataBoxAdder<Gradhatror2cookgb> {
  public:
    static std::string ClassID() { return "Gradhatror2cookgb";}
    static std::string Help() {
      return
	"Gradhatror3cookgb                                                 \n"
	"Compute the gradient of hat{r}^i/r^3                              \n"
	"OPTIONS:                                                          \n"
	"    Output = string                                               \n"
	"PRESENTS to the DataBox                                           \n"
	"  Tensor<DataMesh>              [Output]                            ";
    };
  public:
    Gradhatror2cookgb(const std::string& opts);
  public:
    std::string Output()         const {return mOutput;}
    const result_type& GetData() const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mOutput;
    mutable result_type mResult;
  };

}
