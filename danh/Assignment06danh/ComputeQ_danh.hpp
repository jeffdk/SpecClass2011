/// \file
/// Defines the ComputeItem ComputeItems::ComputeQ_danh.
#ifndef ComputeQ_danh_hpp
#define ComputeQ_danh_hpp

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

namespace ComputeItems {

/// Computes a Tensor<DataMesh> of rank 1 holding \hat{r}^i/r^3
class ComputeQ_danh : public ComputeItem<Tensor<DataMesh> >,
                      private InstantiateDataBoxAdder<ComputeQ_danh>
{
public: 
  static std::string ClassID() { return "ComputeQ"; }
  static std::string Help() { 
    return 
      "ComputeQ                                                         \n"
      "Computes a Tensor<DataMesh> of rank 1 holding hat{r}^i/r^3,      \n"
      "where r is the magnitude of the GlobalCoords vector.             \n"
      "                                                                 \n"
      "OPTIONS:                                                         \n"
      "  Output = string;                                               \n"
      "REQUIRES in the DataBox:                                         \n"
      "  MyVector<DataMesh>            'GlobalCoords'                   \n"
      "PRESENTS to the DataBox                                          \n"
      "  <Tensor<DataMesh> >           [Output]                         \n"
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
