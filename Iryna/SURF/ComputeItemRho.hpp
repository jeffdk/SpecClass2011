/// \file
/// Defines ComputeItems::ComputeItemRho
                       
#ifndef ComputeItemRho_hpp                                   
#define ComputeItemRho_hpp

#include <string>
#include "Utils/DataBox/ComputeItem.hpp"                                          
#include "Utils/DataMesh/DataMesh.hpp"                                            
#include "Utils/Tensor/Tensor.hpp"

namespace ComputeItems {                                            
  ///               
  class ComputeItemRho: public ComputeItem<Tensor<DataMesh> >,          
                     private InstantiateDataBoxAdder<ComputeItemRho> {   
  public: 
    static std::string ClassID() { return "ComputeItemRho"; }           
    static std::string Help() {                                      
      return 
        "ComputeItemRho                                              \n"
        "Takes density as an argument and returns that density       \n"
        "multiplied by some SphericalHarmonicY                       \n"
        "OPTIONS:                                                    \n"
        "   Input    = string; #name of original rho                 \n"
        "               int, l, m                                    \n"
        "   Output   = string;  #name of output                        ";
    
    };
  public:
    ComputeItemRho(const std::string& opts);                            
                                                                      
  public:
    std::string Output()           const { return mOutput; }        
    const result_type& GetData()   const { return mResult; }         
    void MultiplyRhoByYlm(const DataBoxAccess& box, int l, 
                          int m) const;             
  private:
    std::string mOutput;                                             
    mutable result_type mResult;                                    
  }; 

}

#endif
