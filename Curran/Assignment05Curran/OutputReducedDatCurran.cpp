#include "OutputReducedDatCurran.hpp"

#include <cmath>
#include <fstream>
#include <sstream>

#include "Utils/ErrorHandling/Assert.hpp"
#include "Utils/ErrorHandling/Require.hpp"
#include "Utils/IO/CachedOfStream.hpp"
#include "Utils/LowLevelUtils/ConvertNumberToString.hpp"
#include "Utils/MyContainers/MyVector.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace OneDimDataWriters {

/* Utility Function */
double SeparationAngle(const double x0, const double y0,
                       const double x1, const double y1,
                       const double x2, const double y2) {
    const double a1 = atan2(y1-y0, x1-x0);
    const double a2 = atan2(y2-y1, x2-x1);
    double da = fabs(a2 - a1);
    if (da > M_PI) {
        da = 2.0*M_PI - da;
    }
    return da;
}

ReducedDatCurran::ReducedDatCurran(const std::string& opts,
                                   const std::string& base_name) :
    base_name_(base_name) {
    OptionParser parser(opts, Help());
    min_angle_ = parser.Get<double>("MinAngle");
}

void ReducedDatCurran::TruncateFile() const {
    // Do nothing; this class does not maintain an open file
}

void ReducedDatCurran::AppendToFileImpl(const double time,
                                        const MyVector<double>& x,
                                        const MyVector<double>& y) const {
    const int n = x.Size();
    ASSERT(y.Size() == n, "x and y must have the same size");

    // Open file
    std::ostringstream file_name;
    file_name << base_name_ << "_t" << time << ".dat";
    CachedOfStream out(file_name.str());

    // Handle small vectors
    if (n == 0) {
        return;
    } else if (n == 1) {
        out << DoubleToString(x[0], 16) << "   " <<
               DoubleToString(y[0], 16) << std::endl;
        return;
    }

    double x0 = x[0];
    double y0 = y[0];
    double x1 = x[1];
    double y1 = y[1];

    // Output first points
    out << DoubleToString(x0, 16) << "   " <<
           DoubleToString(y0, 16) << std::endl;
    out << DoubleToString(x1, 16) << "   " <<
           DoubleToString(y1, 16) << std::endl;

    for (int i = 2; i < n-1; ++i) {
        double x2 = x[i];
        double y2 = y[i];

        if (SeparationAngle(x0, y0, x1, y1, x2, y2) >= min_angle_) {
            out << DoubleToString(x[i], 16) << "   " <<
                   DoubleToString(y[i], 16) << std::endl;
        }

        // Shift history
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    // Output last point
    if (n > 2) {
        out << DoubleToString(x[n-1], 16) << "   " <<
               DoubleToString(y[n-1], 16) << std::endl;
    }
}

}

