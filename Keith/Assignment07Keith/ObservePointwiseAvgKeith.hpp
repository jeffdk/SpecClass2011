#ifndef ObserverPointwiseAvgKeith_hpp
#define ObserverPointwiseAvgKeith_hpp

#include "Dust/Domain/Observer.hpp"

namespace Observers {
  class PointwiseAvgKeith : public Observer {
  public: 
    static std::string ClassID() {return "PointwiseAvg";}
    static std::string    Help() {
      return 
        "PointwiseAvg:\n"
        "  Returns average over all components of a TDm over all points  \n"
        "on the Domain.                                                  \n"
        "OPTIONS:                                                        \n"
        "   Input    =string;        # which Tensor to act on            \n"
        "   Filename = string;       # Output filename                   \n"
        ;
    }
  public:
    PointwiseAvgKeith(const std::string &Opts, const DataBox&, 
                      const std::string& Dir);
    void Observe(const DataBox& box,
                 const double TimeForDumpFiles,
                 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName,mInput;
  };

} // end Namespace Observers

#endif // ObserverPointwiseAvgKeith_hpp
