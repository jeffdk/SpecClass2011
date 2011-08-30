#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/IO/CachedOfStream.hpp"

#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iostream>

namespace OneDimDataWriters {

  class OutputReducedDatIryna: public OneDimDataWriter,
     Factory::Register<OutputReducedDatIryna>
  {
     public: 
	static std::string ClassID() {return "rdatIryna";}
	static std::string Help() {
           return ClassID() + "\n"
              "Output: Two columns containing x_i and y_i with each i-th    \n"
	      "data point omitted.                                          \n"
	      "OPTIONS: MinAngle = double;  if abs(180 - angle) < MinAngle, \n"
	      "discard the i-th data point. \n" ;
        }
        OutputReducedDatIryna(const std::string& opts, const std::string& BaseName);
    
	void TruncateFile() const; 

     private:
        const std::string mBaseName;
        double mMinAngle;

	void AppendToFileImpl(const double time, 
			      const MyVector<double>& x,
			      const MyVector<double>& y) const;
     };
};
