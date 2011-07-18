//////////////////////////////////////////////////////////////////////////
/// Assignment02Bohn
///
/// Here are defined two functions which accept two vectors and perform
/// mathematical operations on them.
///
//////////////////////////////////////////////////////////////////////////


/// Here is defined a function that adds two vectors together, component
/// by component, and returns the result. Each component of each vector
/// should be a double.
///
/// @param A     first vector addend
/// @param B     second vector addend
/// @return      the vectors' sum
MyVector<double> SumVectors(const MyVector<double>& A,
                            const MyVector<double>& B);

/// Here is a function which performs A / B, element by elemnt, and
/// returns the result.  Each component of each vector should be a double
///
/// @param numerator     the numerator of the quotient
/// @param denominator   the denominator of the quotient
/// @return              the vectors' quotient
MyVector<double> DivideVectors(const MyVector<double>& numerator,
                               const double& denominator);
