#ifndef ASSIGNMENT04CURRAN_TOPOLOGYMESH_FAKECURRAN_HPP_
#define ASSIGNMENT04CURRAN_TOPOLOGYMESH_FAKECURRAN_HPP_
 
#include "Mesh_FakeCurran.hpp"
#include "Topology_FakeCurran.hpp"

template <typename> class MyVector;
class IndexMap;
 
class TopologyMesh: public Mesh, public Topology {
  public:     
    TopologyMesh(const Mesh& ExistingMesh, 
                 const Topology& rTopology,
                 const MyVector<const IndexMap*>& rIndexMapVec);
    TopologyMesh(const TopologyMesh&);
    ~TopologyMesh();
 
    // Member functions would normally be declared here.
};
 
#endif  // ASSIGNMENT04CURRAN_TOPOLOGYMESH_FAKECURRAN_HPP_

