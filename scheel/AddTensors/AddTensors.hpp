#ifndef AddTensors_hpp
#define AddTensors_hpp

#include <string>
#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

namespace ComputeItems {

  /// Adds two Tensor<DataMesh>es componentwise.
  class AddTensors : public ComputeItem<Tensor<DataMesh> >,
		     private InstantiateDataBoxAdder<AddTensors> {
  public: 
    static std::string ClassID() { return "AddTensors"; }
    static std::string Help() { 
      return ClassID() +                                                  "\n"
        "Adds two Tensor<DataMesh>es component by component.               \n"
        "OPTIONS:                                                          \n"
        "   A      = string;                                               \n"
        "   B      = string;                                               \n"
	"   Output = string;  # A+B                                        \n"
	"REQUIRES in DataBox:                                              \n"
        "   Tensor<DataMesh>     [A,B]                                     \n"
        "PRESENTS to the DataBox                                           \n"
        "   Tensor<DataMesh>     [Output=A+B]                              \n"
	;
    };
  public:
    AddTensors(const std::string& opts);
    std::string Output()              const {return mOutput;}
    const result_type& GetData()      const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mA,mB,mOutput;
    mutable result_type mResult;
  };
  
} // End of namespace ComputeItems
#endif // AddTensors_hpp
