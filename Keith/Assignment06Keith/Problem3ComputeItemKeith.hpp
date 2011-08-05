/// \file
/// Defines ComputeItems::Problem3ComputeItemKeith.
#ifndef Problem3ComputeItemKeith_hpp_
#define Problem3ComputeItemKeith_hpp_

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"

namespace ComputeItems {

  /// ComputeItem for my solution to problem 3 Assignment06 for the 2011
  /// spec summer course.
  class Problem3ComputeItemKeith: 
    public ComputeItem<Tensor<DataMesh> >,
    private InstantiateDataBoxAdder<Problem3ComputeItemKeith> {
    
  public:
    static std::string ClassID() { return "Problem3ComputeItemKeith"; }
    static std::string Help() {
      return 
        "Problem3ComputeItemKeith:                                       \n"
        "  Computes x^i/r^3                                              \n"
        "OPTIONS:                                                        \n"
        "  Output  = string;                                             \n"
        ;
    };
  public:
    Problem3ComputeItemKeith(const std::string& opts);
    std::string Output()           const {return mOutput;}
    const result_type& GetData()   const {return mResult;}
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    std::string mOutput;
    mutable result_type mResult;
  };

} // end Namespace ComputeItems

#endif
