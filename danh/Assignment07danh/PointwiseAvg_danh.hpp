/// \file
/// Declares class Observers::PointwiseAvg_danh
#ifndef Observer_PointwiseAvg_danh_hpp
#define Observer_PointwiseAvg_danh_hpp

#include "Dust/Domain/Observer.hpp"

namespace Observers {
  class PointwiseAvg_danh : public Observer {
  public:
    static std::string ClassID() {return "PointwiseAvg_danh";}
    static std::string    Help() {
      return "PointwiseAvg_danh                                             \n"
        "   Returns the pointwise average of all components of a TDm over   \n"
        "   all points on the Domain.                                       \n"
        "OPTIONS:                                                           \n"
        "   Input    = string;       # which Tensor to act on               \n"
        "   Filename = string;       # Output filename                      \n"
      ;
    }
  public:
    PointwiseAvg_danh(const std::string &Opts,
                      const DataBox&,const std::string& Dir);
    void Observe(const DataBox& box,
                 const double TimeForDumpFiles,
                 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName,mInput;
  };
}
#endif // Observer_PointwiseAvg_danh_hpp
