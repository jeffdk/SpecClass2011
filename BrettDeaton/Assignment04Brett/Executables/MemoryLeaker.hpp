class MemoryLeaker {
public:
  MemoryLeaker(const int n) 
    : pLeaky(new double[n]) {}
  ~MemoryLeaker() {delete pLeaky;}
  void Reset(const int n) {
    pLeaky = new double[n];
  }
private:
  double * pLeaky;  
};
