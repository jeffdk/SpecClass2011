class MemoryLeaker {
public:
  MemoryLeaker(const int n) 
    : pLeaky(new double[n]) {}
  ~MemoryLeaker() {delete[] pLeaky;}
  void Reset(const int n) {
    // Need to make sure that pLeaky stops pointing at previous
    // location in memory before creating it again
    delete[] pLeaky;
    pLeaky = new double[n];
  }
private:
  double * pLeaky;  
};
