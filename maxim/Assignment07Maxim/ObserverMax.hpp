#ifndef Observer_Max_hpp
#define Observer_Max_hpp
#include "Dust/Domain/Observer.hpp"
 
namespace Observers {
  class Max : public Observer {
  public: 
    static std::string ClassID() {return "Max";}
    static std::string    Help() {
      return "Max                                                           \n"
        "   Returns maximum over all components of a TDm over all points on \n"
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
#endif // Observer_Max_hpp
