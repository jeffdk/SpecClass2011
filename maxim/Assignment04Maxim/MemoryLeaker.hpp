#ifndef MemoryLeaker_hpp
#define MemoryLeaker_hpp

class MemoryLeaker {
public:
  MemoryLeaker(const int n);
  ~MemoryLeaker();
  void Reset(const int n);
private:
  double * pLeaky;
};

#endif
