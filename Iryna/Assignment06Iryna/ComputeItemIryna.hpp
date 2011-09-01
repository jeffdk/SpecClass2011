/// \file
/// Defines ComputeItems::ComputeItemIryna
                       
#ifndef ComputeItemIryna_hpp                                   
#define ComputeItemIryna_hpp

#include <string>
#include "Utils/DataBox/ComputeItem.hpp"                                          
#include "Utils/DataMesh/DataMesh.hpp"                                            
#include "Utils/Tensor/Tensor.hpp"

namespace ComputeItems {                                            
  ///               
  class ComputeItemIryna: public ComputeItem<Tensor<DataMesh> >,          
                     private InstantiateDataBoxAdder<ComputeItemIryna> {   
  public: 
    static std::string ClassID() { return "ComputeItemIryna"; }           
    static std::string Help() {                                      
      return 
        "ComputeItemIryna                                            \n"
        "OPTIONS:                                                    \n"
        "   Output   = string;  #name of output                      \n"
        "Computes a Tensor<DataMesh> of rank 1 holding r^i/r^3 and   \n"
	"presenting it into the DataBox under the name 'Q'.            ";
    
    };
  public:
    ComputeItemIryna(const std::string& opts);                            
                                                                      
  public:
    std::string Output()           const { return mOutput; }        
    const result_type& GetData()   const { return mResult; }         
    void RecomputeData(const DataBoxAccess& box) const;             
  private:
    std::string mOutput;                                             
    mutable result_type mResult;                                    
  }; 

}

#endif
