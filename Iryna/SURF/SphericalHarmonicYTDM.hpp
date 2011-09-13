//---------------------------------------------------------------------------
//
// Computes real-valued spherical harmonics Y_lm(theta,phi) at each point 
// of a Tensor<DataMesh>, given by the <DataMesh>es theta and phi.
//
//---------------------------------------------------------------------------

#ifndef SphericalHarmonicYTDM_H
#define SphericalHarmonicYTDM_H
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"

Tensor<DataMesh> SphericalHarmonicYTDM(int l, int m, const DataMesh theta, 
                               const DataMesh phi, const Mesh mesh);

#endif /* SphericalHarmonicYTDM_H */
