#ifndef ASSIGNMENT04CURRAN_SUBDOMAIN_CURRAN_HPP_
#define ASSIGNMENT04CURRAN_SUBDOMAIN_CURRAN_HPP_

// Includes
#include <string>                       // Needed for mName
#include "CoordMapCache_FakeCurran.hpp" // Needed for mMap
#include "TopologyMesh_FakeCurran.hpp"  // Needed for inheritance

// Forward Declarations
template <typename> class MyVector;
class DataMesh;
class CoordMap;
 
class Subdomain : public TopologyMesh {
  public: 
    Subdomain(const TopologyMesh& rTopMesh, 
              const CoordMap& rCoordMap,
              const std::string& name);
    Subdomain(const Subdomain& rSubdomain);
 
    const std::string& Name() const { return mName; }
 
    bool IsContainedGlobal(const MyVector<double> & x, 
                           const double eps=0.0) const;
 
    const CoordMapCache& Map() const {return mMap;}
 
    const MyVector<DataMesh>& TopolCoords() const;
    const MyVector<DataMesh>& GlobalCoords() const;
 
  private:
    CoordMapCache mMap;
    const std::string mName; 
};
 
bool operator==(const Subdomain& l, const Subdomain& r);
inline bool operator!=(const Subdomain& l, const Subdomain& r) {
  return !(l==r); 
};
 
Subdomain CreateSubdomain(const std::string& opts);
 
#endif  // ASSIGNMENT04CURRAN_SUBDOMAIN_CURRAN_HPP_

