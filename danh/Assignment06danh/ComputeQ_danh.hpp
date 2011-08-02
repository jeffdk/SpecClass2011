/// \file
/// Defines the ComputeItem ComputeItems::ComputeQ.
#ifndef ComputeQ_danh_hpp
#define ComputeQ_danh_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

namespace ComputeItems {

/// Adds a corotation \f$\vec\Omega\times\vec r\f$ to a vector.
class ComputeQ_danh : public ComputeItem<Tensor<DataMesh> >,
                      private InstantiateDataBoxAdder<ComputeQ_danh>
{
public: 
  static std::string ClassID() { return "ComputeQ"; }
  static std::string Help() { 
    return 
      "ComputeQ                                                        \n"
      "Help text.                                                      \n"
      "OPTIONS:                                                        \n"
      "   Output = string;                                             \n"
      "REQUIRES in the DataBox:                                        \n"
      "  MyVector<DataMesh>            'GlobalCoords'                  \n"
      "PRESENTS to the DataBox                                         \n"
      "  <Tensor<DataMesh> >           [Output]                        \n"
    ;
  };
public:
  ComputeQ_danh(const std::string& opts);
public:
  std::string Output()         const {return mOutput;}
  const result_type& GetData() const {return mResult;}
  void RecomputeData(const DataBoxAccess& box) const;
private:
  std::string mOutput;
  mutable result_type mResult;
};
  
} // namespace ComputeItems

#endif
