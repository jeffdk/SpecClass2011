/// \file
/// Defines the ComputeItem ComputeItems::DescriptiveName_Bohn.

#ifndef DescriptiveName_Bohn__hpp
#define DescriptiveName_Bohn__hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include <string>

class DataMesh;

namespace ComputeItems {

  /// Creates a rank one Tensor<DataMesh> holding \frac{x^i}{r^3}
  /// NOTE: the homework example uses x^i/r^3, but the question asks explicitly
  /// for hat{r}^i / r^3, which isn't the same.  I'm doing x^i / r^3
  /// See Help() for details.
  class DescriptiveName:
    public ComputeItem<Tensor<DataMesh> >,
    private InstantiateDataBoxAdder<DescriptiveName>
  {
  public:
    static std::string ClassID() { return "DescriptiveName"; }
    static std::string Help() {
      return
	"DescriptiveName                                                    \n"
	"   Creates a Tensor<DataMesh> of rank 1 holding x^i / r^3          \n"
	"OPTIONS:                                                           \n"
	"  Output   = string;  # name of result                             \n"
	"REQUIRES in DataBox:                                               \n"
	"  MyVector<DataMesh>  # GlobalCoords                               \n"
  "PRESENTS to the DataBox:                                           \n"
  "  <Tensor<DataMesh> > # [Output] the output TDm                    \n";
    };

  public:
    DescriptiveName(const std::string& opts);
  public:
    std::string Output()         const { return mOutput; }
    const result_type& GetData() const { return mResult; }
    void RecomputeData(const DataBoxAccess& box) const;
  private:
    mutable result_type mResult;
    std::string mOutput;
  };
}


#endif
