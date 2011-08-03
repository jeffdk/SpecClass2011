// ComputeItems/UnitVector.hpp

#ifndef UnitVector_hpp
#define UnitVector_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"


namespace ComputeItems {
  /// Computes the determinant of a second-rank Tensor. 
  class UnitVectorR: public ComputeItem<Tensor<DataMesh> >,
		     private InstantiateDataBoxAdder<UnitVectorR> {
  public: 
    static std::string ClassID() { return "UnitVectorR"; }
    static std::string Help() { 
      return 
	"UnitVectorR                                                 \n"
	"Compute r^{i}/|r|                                           \n"
	"OPTIONS:                                                    \n"
	"   Output   = string                                        \n"
	"REQUIRES in the DataBox:                                    \n"
	"  MyVector<DataMesh> GlobalCoords                           \n"
	"PRESENTS to the DataBox                                     \n"
	"  Tensor<DataMesh>              [Output]                      ";
    };
  public:
    UnitVectorR(const std::string& opts);
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
