#ifndef ASSIGNMENT05CURRAN_OUTPUTREDUCEDDATCURRAN_HPP_
#define ASSIGNMENT05CURRAN_OUTPUTREDUCEDDATCURRAN_HPP_

#include <string>

#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/MiscUtils/Factory.hpp"
template<typename> class MyVector;

namespace OneDimDataWriters {

class ReducedDatCurran: public OneDimDataWriter,
                               Factory::Register<ReducedDatCurran> {
  public:
    ReducedDatCurran(const std::string& opts, const std::string& base_name);

    static std::string ClassID() {
        return "ReducedDatCurran";
    }
    static std::string Help() {
        return
"ReducedDatCurran                                                        \n"
"Outputs dat files with columns for x and y, but skips points whose      \n"
"  angular separation is small, thus compressing the output while        \n"
"  producing a similar-looking plot.                                     \n"
"OPTIONS:                                                                \n"
"  MinAngle = double;  # Minimum angular separation that will result in  \n"
"                          a point being written (in radians)            \n";
    }
    void TruncateFile() const;

  private:
    const std::string base_name_;
    double min_angle_;
 
    void AppendToFileImpl(const double time,
                          const MyVector<double>& x,
                          const MyVector<double>& y) const;
};
 
}

#endif  // ASSIGNMENT05CURRAN_OUTPUTREDUCEDDATCURRAN_HPP_

