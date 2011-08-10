#ifndef ASSIGNMENT07CURRAN_OBSERVEPOINTWISEAVGCURRAN_HPP_
#define ASSIGNMENT07CURRAN_OBSERVEPOINTWISEAVGCURRAN_HPP_

#include <string>

#include "Dust/Domain/Observer.hpp"
class DataBox;
 
namespace Observers {

/**
 * Computes the average value of all components of a TDm over all points in a
 * Domain.
 *
 * @author Curran D. Muhlberger \<curran@astro.cornell.edu\>
 * @date 2011-07-28
 */
class PointwiseAvgCurran : public Observer {
  public: 
    PointwiseAvgCurran(const std::string& opts, const DataBox& box,
                       const std::string& dir); 

    static std::string ClassID() {
        return "PointwiseAvgCurran";
    }
    static std::string Help() {
        return
"PointwiseAvgCurran                                                      \n"
"Computes the average value of all components of a TDm over all points in\n"
"  a Domain.                                                             \n"
"OPTIONS:                                                                \n"
"  Input    = string;       # Name of TDm to compute average of          \n"
"  Filename = string;       # Name of file to write output to            \n"
"REQUIRES in Subdomain DataBoxes:                                        \n"
"  TDm : [Input]                                                         \n";
    }
    void Observe(const DataBox& box, const double time,
                 const std::string& first_col) const;

  private:
    std::string input_name_;
    std::string file_path_;
};

}

#endif // ASSIGNMENT07CURRAN_OBSERVEPOINTWISEAVGCURRAN_HPP_

