///
/// \file
/// Defines the ComputeItem ComputeItems::Hw6CompItemfhebert
#ifndef HW6_COMPITEM_hpp
#define HW6_COMPITEM_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"

class DataMesh;

namespace ComputeItems {

  /// Computes a 1/r^2 radial vector field

  class Hw6CompItemfhebert:
      public ComputeItem<Tensor<DataMesh> >,
		  private InstantiateDataBoxAdder<Hw6CompItemfhebert> {
  public: 
    static std::string ClassID() { return "Hw6CompItemfhebert"; }
    static std::string Help() { 
      return 
	    "Hw6CompItemfhebert                                          \n"
	    "Compute the vector field \\hat{r}/r^2 from a GlobalCoords   \n"
      "which holds the x,y,z values. Uses the Mesh of the Global-  \n"
      "Coords to construct its output tensor.                      \n"
	    "OPTIONS:                                                    \n"
	    "REQUIRES in the DataBox:                                    \n"
	    "  MyVector<DataMesh>            'GlobalCoords'              \n"
	    "PRESENTS to the DataBox                                     \n"
	    "  Tensor<DataMesh>              [Output]                      ";
    };
  
    Hw6CompItemfhebert(const std::string& opts);
    
    std::string Output()         const {return mOutput;}
    const result_type& GetData() const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mOutput;
    mutable result_type mResult;
  }; 

} 

#endif 
