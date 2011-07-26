

void OneDimDataWriter::ApendToFile(const double time,
                                   const MyVector<double>& x,
                                   const MyVector<double>& y) const {
  REQUIRE(x.Size() == y.Size(), "Size mismatch");
  AppendToFileImpl(time, x, y);
}

namespace OneDimDataWriters {
  Class OutputReducedDat_Bohn: public OneDimDataWriter,
    Factory::Register<OutputReducedDat_Bohn> {
  public:
    static string ClassID() { return "rdatBohn"; }
    static string Help() {
      return ClassID() + "\n"
    "Output scatter data which emits all superfluous points.  These points   \n"
    "are defined by all points where, if emitted, a line graph would remain  \n"
    "unchanged.                                                              \n"
    "-- NO OPTIONS --                                                       \n";
    };
    OutputReducedDat_Bohn(const string& opts, const string& BaseName):
      mFileName(BaseName+".rdatBohn") {
      REQUIRE(opts.empty(), Help());
    };
    void Truncate

