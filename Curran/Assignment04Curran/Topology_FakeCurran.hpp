#ifndef ASSIGNMENT04CURRAN_TOPOLOGY_FAKECURRAN_HPP_
#define ASSIGNMENT04CURRAN_TOPOLOGY_FAKECURRAN_HPP_
 
template <typename> class MyVector;
class IrreducibleTopology;
 
class Topology {
  public:
    Topology(const MyVector<const IrreducibleTopology*>& irrTop);
    Topology(const Topology& rhs); 
    ~Topology();
 
    // Member functions would normally be declared here
};
 
#endif  // ASSIGNMENT04CURRAN_TOPOLOGY_FAKECURRAN_HPP_

