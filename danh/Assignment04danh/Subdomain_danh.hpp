#ifndef Subdomain_hpp
#define Subdomain_hpp
 
#include "Dust/Domain/Topology/TopologyMesh.hpp"
#include "Dust/Domain/Subdomain/CoordMapCache.hpp"
#include <string>
 
class CoordMap;
class DataMesh;
template <typename> class MyVector;
 
class Subdomain : public TopologyMesh {
public: 
  Subdomain(const TopologyMesh & rTopMesh, 
        const CoordMap & rCoordMap,
        const std::string& name);
  Subdomain(const Subdomain& rSubdomain);
 
public: 
  const std::string& Name() const { return mName; }
 
  bool IsContainedGlobal(const MyVector<double> & x, 
             const double eps=0.0) const;
 
  const CoordMapCache& Map() const {return mMap;}
 
 
  const MyVector<DataMesh>& TopolCoords() const;
  const MyVector<DataMesh>& GlobalCoords() const;
 
private:
  CoordMapCache mMap;
  const std::string mName; 
 
};  // class Subdomain
 
bool operator==(const Subdomain& l, const Subdomain& r);
inline bool operator!=(const Subdomain& l, const Subdomain& r) {
  return !(l==r); 
};
 
Subdomain CreateSubdomain(const std::string& opts);
 
#endif  // Subdomain_hpp
