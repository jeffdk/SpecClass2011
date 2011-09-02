#ifndef ObservePointwiseAvgIryna_hpp
#define ObserverPointwiseAvgIryna_hpp
#include "Dust/Domain/Observer.hpp"
 
namespace Observers {
  class PointwiseAvgIryna : public Observer {
  public: 
    static std::string ClassID() {return "PointwiseAvgIryna";}
    static std::string    Help() {
      return "PointwiseAvgIryna                                             \n"
        "   Returns the average of all the components of a TDm over all     \n"
        "   points on the Domain.                                           \n"
        "OPTIONS:                                                           \n"
        "   Input    =string;        # which Tensor to act on               \n"
        "   Filename = string;       # Output filename                      \n"
	;
    }
  public:
    PointwiseAvgIryna(const std::string &Opts, 
	const DataBox&,const std::string& Dir);
    void Observe(const DataBox& box,
                 const double TimeForDumpFiles,
                 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName,mInput;
  };
}
#endif 
