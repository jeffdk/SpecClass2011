#ifndef Subdomain_hpp
#define Subdomain_hpp

#include "TopologyMesh_Fake.hpp" // inherited from this
#include "CoordMapCache_Fake.hpp" // member variable
#include <string> // member variable

class CoordMap; // class declaration sufficient here

// the following two are not strictly needed for this to compile:
//  they are already included by CoordMapCache, for instance.
// however, adding these definitions will prevent this class from
// breaking should the included headers stop providing the declaration
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
