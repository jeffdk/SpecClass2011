#ifndef ComputeQhohejd8_hpp
#define ComputeQhohejd8_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"

namespace ComputeItems {
  /// Computes hat{r}^i/r^3
  class ComputeQhohejd8: public ComputeItem<Tensor<DataMesh> >,
		         private InstantiateDataBoxAdder<ComputeQhohejd8> {
  public: 
    static std::string ClassID() { return "ComputeQhohejd8"; }
    static std::string Help() { 
      return 
	"ComputeQhohejd8                                            \n"
	"Computes hat{r}^i/r^3 for the sample data given in          \n"
	"Assignment 6.                                               \n"
	"OPTIONS:                                                    \n"
	"   Input    = string                                        \n"
	"   Output   = string                                        \n"
	"PRESENTS to the DataBox                                     \n"
	"  Tensor<DataMesh>              [Output]                      ";
    };
  public:
    ComputeQhohejd8(const std::string& opts);
  public:
    std::string Output()         const {return mOutput;}
    const result_type& GetData() const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mOutput;
    mutable result_type mResult;
  };
}

#endif
