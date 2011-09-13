/// Defines ComputeItems::ComputeItemRho
                       
#ifndef ComputeItemRho_hpp                                   
#define ComputeItemRho_hpp

#include <string>
#include "Utils/DataBox/ComputeItem.hpp"                                          
#include "Utils/DataMesh/DataMesh.hpp"                                            
#include "Utils/Tensor/Tensor.hpp"

namespace ComputeItems {                                            
              
  class ComputeItemRho: public ComputeItem<Tensor<DataMesh> >,           
                     private InstantiateDataBoxAdder<ComputeItemRho> {   
  public: 
    static std::string ClassID() { return "ComputeItemRho"; }           
    static std::string Help() {                                      
      return 
        "ComputeItemRho                                                    \n"
        "Takes a Tensor<DataMesh> density, l, and m as arguments           \n"
        "and returns a Tensor<DataMesh> of the density multiplied by the   \n"
        "SphericalHarmonicY given by the respective l and m.               \n"
        "OPTIONS:                                                          \n"
        "   Input    = string; #name of original rho                       \n"
        "              int l, m; spherical harmonic operator               \n"
        "   Output   = string;  #name of output                              ";
    
    };
  public:
    ComputeItemRho(const std::string& opts);                            
                                                                      
  public:
    std::string Output()           const { return mOutput; } 
    const result_type& GetData()   const { return mResult; }         
    void RecomputeData(const DataBoxAccess& box) const;             
  private:
    std::string mInput, mOutput; 
    int l;
    int m;                                          
    mutable result_type mResult;                                    
  }; 

}

#endif
