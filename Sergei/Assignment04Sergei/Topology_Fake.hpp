#ifndef INCLUDED_Topology_hpp
#define INCLUDED_Topology_hpp

template <typename> class MyVector;
class IrreducibleTopology;

class Topology {
public:
  Topology(const MyVector<const IrreducibleTopology*>& irrTop);
  Topology(const Topology& rhs); 
  ~Topology();

  // Member functions would normally be declared here
};

#endif  // Topology_hpp