#ifndef OutputReducedData_fhebert_hpp
#define OutputReducedData_fhebert_hpp

#include "Utils/IO/OneDimDataWriter.hpp"

using std::string;

namespace OneDimDataWriters {

  class OutputReducedDat_fhebert: public OneDimDataWriter,
    Factory::Register<OutputReducedDat_fhebert>
  {
    public:
      static string ClassID() {return "rdatfh";}
      static string Help() {
        return ClassID() + "\n"
        "file output: saves each x_i, y_i in a separate column.             \n"
        "reduces data so that nearly-colinear points are eliminated, saving \n"
        "space in both data files and plots.                                \n"
        " OPTIONS:                                                          \n"
        " MinAngle = double; #min allowed angle before elimination (radians)\n";
      };
    
      OutputReducedDat_fhebert(const string& Opts, const string& BaseName);
      void TruncateFile() const {};

    private:
      const string mBaseName;
      mutable int mCount;
      double mMinAngle;

      void AppendToFileImpl(const double time,
                            const MyVector<double>& x,
                            const MyVector<double>& y) const;
  };
}

#endif
