#ifndef ObservePointwiseAvg_hpp
#define ObservePointwiseAvg_hpp
#include "Dust/Domain/Observer.hpp"
 
namespace Observers {
  class PointwiseAvg : public Observer {
  public: 
    static std::string ClassID() {return "PointwiseAvg";}
    static std::string    Help() {
      return "PointwiseAvg                                                  \n"
        "   Returns average over all components of a TDm over all points on \n"
        "   the Domain.                                                     \n"
        "OPTIONS:                                                           \n"
        "   Input    =string;        # which Tensor to act on               \n"
        "   Filename = string;       # Output filename                      \n"
	;
    }
  public:
    Max(const std::string &Opts, 
	const DataBox&,const std::string& Dir); // #1.
    void Observe(const DataBox& box,
                 const double TimeForDumpFiles,
                 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName,mInput;
  };
}
#endif // ObservePointwiseAvg_hpp
