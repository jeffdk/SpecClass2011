#ifndef Observe_Pointwise_Avg_hpp
#define Observe_Pointwise_Avg_hpp
#include "Dust/Domain/Observer.hpp"
 
namespace Observers {
  class PointwiseAvg : public Observer {
  public: 
    static std::string ClassID() {return "PointwiseAvg";}
    static std::string    Help() {
      return "PointwiseAvg                                                      \n"
        "   Returns the average over all components of a TDm over all points on \n"
        "   the Domain.        		                                            \n"
        "OPTIONS:                                                           	\n"
        "   Input    =string;        # which Tensor to act on               	\n"
        "   Filename = string;       # Output filename                      	\n"
	;
    }
  public:
    PointwiseAvg(const std::string &Opts, 
				 const DataBox&,const std::string& Dir);

    void Observe(const DataBox& box,
                 const double TimeForDumpFiles,
                 const std::string& FirstColumnInDatFiles) const;
  private:
    std::string mFileName,mInput;
  };
}
#endif // Observe_Pointwise_Avg_hpp
