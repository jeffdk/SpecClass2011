#ifndef ASSIGNMENT04CURRAN_COORDMAPCACHE_FAKECURRAN_HPP_
#define ASSIGNMENT04CURRAN_COORDMAPCACHE_FAKECURRAN_HPP_

class CoordMap;
class TopologyMesh;
class DataMesh;
template <typename> class MyVector;
 
class CoordMapCache {
  public:
    CoordMapCache(const CoordMap& rMap,
                  const TopologyMesh& rTopMesh,
                  const MyVector<DataMesh>& rTopolCoords);
    ~CoordMapCache();
 
    // Member functions would normally be declared here
};
 
#endif  // ASSIGNMENT04CURRAN_COORDMAPCACHE_FAKECURRAN_HPP_

