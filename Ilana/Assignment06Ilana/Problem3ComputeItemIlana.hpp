#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include <string>

namespace ComputeItems {
  class Problem3ComputeItemIlana :
    public ComputeItem<Tensor<DataMesh> >,
    private InstantiateDataBoxAdder<Problem3ComputeItemIlana>
  {
  public:
    static std::string ClassID() {return "Problem3ComputeItemIlana";}
    static std::string Help() {
      return
	"Problem3ComputeItemIlana  \n"
	"Calculates a Tesnor<DataMesh> of rank 1 holding hat{r}^i/f^3   \n"
	"and presents it into the DataBox under the name Q.   \n"
	"OPTIONS:   \n"
	"  Output = string; # Name of output";
	};
  public:
    Problem3ComputeItemIlana(const std::string& opts);
    std::string Output()          const {return mOutput;}
    const result_type& GetData()  const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mOutput;
    mutable result_type mResult;
  };
}
