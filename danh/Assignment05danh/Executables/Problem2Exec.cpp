///
/// \file
/// Program to write output of ComputeProfileAndOutput using a OneDimDataWriter.

#include "Utils/ErrorHandling/BasicMpi.hpp"
#include "StudentProjects/SpecClass2011/danh/Assignment05danh/ComputeProfileAndOutput_danh.hpp"
#include "Utils/StringParsing/OptionParser.hpp"
#include "Utils/IO/OneDimDataWriter.hpp"
#include "Utils/StringParsing/ReadFileIntoString.hpp"
#include <cstdlib>  // for EXIT_SUCCESS

int main(int argc, char** argv) {
  MpiInit(&argc, &argv);

  const std::string helptxt =
    "OneDFormat.input:                                                      \n"
    "Input file for Assignment 5, Problem 2.                                \n"
    "Format   = string;               # Which 1-D output format             \n"
    "Basename = string;               # Output filename (without extension) \n"
    "Times    = double, double, ...;  # Which times to output               \n"
  ;

  // Read the options from the input file
  const std::string options = ReadFileIntoString("OneDFormat.input");
  OptionParser parser(options, helptxt);

  const std::string format     = parser.Get<std::string>("Format");
  const std::string basename   = parser.Get<std::string>("Basename");
  const MyVector<double> times = parser.Get<MyVector<double> >("Times");

  // Write the result of ComputeProfileAndOutput at the given times
  const OneDimDataWriter* pWriter = OneDimDataWriter::Create(format, basename);
  for(int i = 0; i < times.Size(); ++i) {
    ComputeProfileAndOutput(times[i], pWriter);
  }
  delete pWriter;

  MpiFinalize();
  return EXIT_SUCCESS;
}
