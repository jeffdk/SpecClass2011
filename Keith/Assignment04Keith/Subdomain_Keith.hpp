#ifndef Subdomain_hpp
#define Subdomain_hpp

// The goal here is to minimize dependencies in order to minimize
// recompiling time.  

// Includes:
// inheritance requires explicit inclusion.
#include "TopologyMesh_Fake.hpp"

// member data types need explicit inclusion.
#include "CoordMapCache_Fake.hpp"

// standard library dependencies can be left explicit.  Since the
// interface to std lib classes changes very rarely there is basically
// no compiling time cost to including their headers.
#include<string>

// Forward declarations:
// these are already in other headers, but I feel they should be here
// as well for clarity.  Plus it doesn't cost anything, and C++ allows
// multiple declarations of a class.
template <typename> class MyVector;
class DataMesh;
class CoordMap;

 
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
