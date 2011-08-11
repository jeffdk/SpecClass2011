#ifndef PointwiseAvg_hpp
#define PointwiseAvg_hpp
#include "Dust/Domain/Observer.hpp"
 
namespace Observers {
  class PointwiseAvg : public Observer {
  public: 
    static std::string ClassID() {return "PointwiseAvg";}
    static std::string    Help() {
      return "PointwiseAvg                                                  \n"
        "   Returns pointwise average over all components of a TDm over     \n"
        "   all points in the Domain.                                       \n"
        "OPTIONS:                                                           \n"
        "   Input    =string;        # which Tensor to act on               \n"
        "   Filename = string;       # Output filename                      \n"
	;
    }
  public:
    PointwiseAvg(const std::string &Opts, 
	const DataBox&,const std::string& Dir); // #1.
    void Observe(const DataBox& box,
                 const double TimeForDumpFiles,
                 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName,mInput;
  };
}
#endif // Observer_Max_hpp
