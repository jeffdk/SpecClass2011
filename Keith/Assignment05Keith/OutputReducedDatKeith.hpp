
#ifndef OutputReducedDatKeith_hpp
#define OutputReducedDatKeith_hpp

#include "Utils/IO/OneDimDataWriter.hpp"

namespace OneDimDataWriters {

  class OutputReducedDatKeith: 
    public OneDimDataWriter,
    Factory::Register<OutputReducedDatKeith> {
  public:
    static std::string ClassID() { return "OutputReducedDatKeith"; }
    static std::string Help() {
      return "OutputReducedDatKeith:\n"
        "Outputs x and y columns in a seperate file for each call to     \n"
        "  AppendToFileImpl().  Culls the input by computing the angle   \n"
        "  between the last and next line segment.  If this angle is     \n"
        "  below the threshold set by the MinAngle Option, the x,y pair  \n"
        "  will be discarded.                                            \n"
        "OPTIONS:                                                        \n"
        "  MinAngle = double;                                            \n"
        ;
    };
    OutputReducedDatKeith(const std::string& opts, 
                          const std::string& BaseName);
    void TruncateFile() const;
  private:
    void AppendToFileImpl(const double time,
                          const MyVector<double>& x,
                          const MyVector<double>& y) const;
    std::string generateFilename(const std::string& basename,
                                 const int& count) const;
  private:
    const std::string mBaseName;
    // counts the number of times that AppendToFileImpl is called.
    mutable int mOutputFileCount;
    double mMinAngle;
    bool mDebug;
  };
    

} // end namespace OneDimDataWriters

#endif
