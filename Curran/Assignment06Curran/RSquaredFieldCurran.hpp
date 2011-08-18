#ifndef ASSIGNMENT06CURRAN_RSQUAREDFIELDCURRAN_HPP_
#define ASSIGNMENT06CURRAN_RSQUAREDFIELDCURRAN_HPP_

#include <string>

#include "Utils/DataBox/ComputeItem.hpp"
#include "Utils/DataBox/InstantiateDataBoxAdder.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/Tensor/Tensor.hpp"
class DataBoxAccess;

namespace ComputeItems {

/**
 * Computes an rhat/r^2 vector field from global coordinates.
 *
 * @author Curran D. Muhlberger \<curran@astro.cornell.edu\>
 * @date 2011-08-18
 */
class RSquaredFieldCurran :
        public ComputeItem<Tensor<DataMesh> >,
        private InstantiateDataBoxAdder<RSquaredFieldCurran> {
  public:
    RSquaredFieldCurran(const std::string& opts);

    static std::string ClassID() {
        return "RSquaredFieldCurran";
    }
    static std::string Help() {
        return
"RSquaredFieldCurran:                                                    \n"
"Computes x^i/r^3 from global coordinates.                               \n"
"OPTIONS:                                                                \n"
"  Output = string;  # Name of TDm to store Q^i                          \n"
"REQUIRES in the DataBox:                                                \n"
"  MDm          : [GlobalCoords]                                         \n"
"PRESENTS to the DataBox                                                 \n"
"  TDm (Rank=1) : [Output]                                               \n";
    }
    std::string Output() const {
        return output_name_;
    }
    const result_type& GetData() const {
        return result_;
    }
    void RecomputeData(const DataBoxAccess& box) const;

  private:
    std::string output_name_;
    mutable result_type result_;
};

}

#endif // ASSIGNMENT06CURRAN_RSQUAREDFIELDCURRAN_HPP_

