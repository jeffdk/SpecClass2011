#ifndef CoordMapCache_hpp
#define CoordMapCache_hpp
     
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
     
};  // class CoordMapCache
     
#endif   // CoordMapCache_hpp
