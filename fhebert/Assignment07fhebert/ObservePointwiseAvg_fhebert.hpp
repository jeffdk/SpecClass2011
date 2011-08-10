//
// francois hebert, aug 2011
// here i define an observer that returns the average of a TDM
//
// input: a TDM
// output: average value over all DMs and mesh points.
//

#ifndef Observer_PwAvg_fh_hpp
#define Observer_PwAvg_fh_hpp
#include "Dust/Domain/Observer.hpp"
 
namespace Observers {

  class PwAvg : public Observer {
    public: 
      static std::string ClassID() {return "PwAvg";}
      static std::string    Help() {
        return "PwAvg                                                         \n"
          "   Returns the average of a TDM over all the tensor components and \n"
          "   and all spatial points.                                         \n"
          "OPTIONS:                                                           \n"
          "   Input    =string;        # which Tensor to act on               \n"
          "   Filename = string;       # Output filename                      \n"
          ;
      }
    public:
      PwAvg(const std::string &Opts, 
            const DataBox&,const std::string& Dir);

      void Observe(const DataBox& box,
                   const double TimeForDumpFiles,
                   const std::string& FirstColumnInDatFiles) const;
    private:
      std::string mFileName,mInput;
  };
}
#endif
