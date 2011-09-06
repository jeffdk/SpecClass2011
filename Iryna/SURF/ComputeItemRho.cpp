#include "ComputeItemRho.hpp"                                                           
#include "Utils/StringParsing/OptionParser.hpp"
#include "SphericalHarmonicYTDM.hpp"
#include <cmath> 


namespace ComputeItems {

  using std::string;                                       

  ComputeItemRho::ComputeItemRho(const string& opts):     
    mResult(TensorStructure::Empty) {                     
    OptionParser p(opts, Help());                         
    mOutput=p.Get<string>("Output");
  }


  void ComputeItemRho::MultiplyRhoByYlm(const DataBoxAccess& box, int l, 
                                        int m) const {
     //change this line to get rho
     const Tensor<DataMesh>& coords=
                         box.Get<Tensor<DataMesh> >("rho_i");
     const Mesh mesh = box.Get<Mesh>("Mesh");

     Tensor<DataMesh> rho_f(0, "", mesh, 0.0); 
     Tensor<DataMesh> theta(0, "", mesh, 0.0);  
     Tensor<DataMesh> phi(0, "", mesh, 0.0);

     std::cout << "tensor structure rank:"<<coords.Rank()<<"\n";

    // theta = acos(coords[2] / sqrt(coords[0]*coords[0] + coords[1]*coords[1] 
                                                    // + coords[2]*coords[2]));
     //phi = atan(coords[1] / coords[0]);
     
     //for(int i = 0; i < coords.Size(); i++){
       // rho_f[i] = coords[i]*SphericalHarmonicYTDM(l, m, theta, phi); 
     //} 
     /*mResult.assign(mesh.Dim(), "1", mesh);  
     for(int i = 0; i < coords.Size(); i++){
        mResult(i) = coords[i] / (r_sq * sqrt(r_sq));
     }*/    
  }
}
