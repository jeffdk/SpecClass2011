///
/// \file
/// Defines function ComputeProfileAndOutput

#ifndef COMPUTEPROFILEANDOUTPUT_DANH_HPP
#define COMPUTEPROFILEANDOUTPUT_DANH_HPP

class OneDimDataWriter;

/// Compute a profile and output the data with a OneDimDataWriter
/// \param const double t = Time at which to compute the data
/// \param OneDimDataWriter* writer = data writer to use
void ComputeProfileAndOutput(const double t, const OneDimDataWriter* writer);

#endif  // COMPUTEPROFILEANDOUTPUT_DANH_HPP
