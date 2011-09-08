//---------------------------------------------------------------------------
// $Id: SphericalHarmonicY.hpp 283 2003-11-20 22:51:17Z scheel $
//
// Computes real-valued spherical harmonics Y_lm(theta,phi)
//
//---------------------------------------------------------------------------
#ifndef SphericalHarmonicYTDM_H
#define SphericalHarmonicYTDM_H
#include "Utils/Tensor/Tensor.hpp"
#include "Utils/DataMesh/DataMesh.hpp"
#include "Utils/DataBox/DataBox.hpp"

Tensor<DataMesh> SphericalHarmonicYTDM(int l, int m, const Tensor<DataMesh> theta, 
                               const Tensor<DataMesh> phi);

#endif /* SphericalHarmonicYTDM_H */
