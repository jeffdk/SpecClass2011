#include "ComputeItemRho.hpp"                                                           
#include "Utils/StringParsing/OptionParser.hpp"
#include "SphericalHarmonicYTDM.hpp"
#include <cmath> 
#include <stdio.h>
#include <cstdlib>
#include <iostream>


namespace ComputeItems {

  using std::string;                                       

  ComputeItemRho::ComputeItemRho(const string& opts):     
    mResult(TensorStructure::Empty) {                     
    OptionParser p(opts, Help());                         
    mOutput=p.Get<string>("Output");
    mInput=p.Get<string>("Input");
    l = p.Get<int>("l");
    m = p.Get<int>("m");
  }
  

  void ComputeItemRho::RecomputeData(const DataBoxAccess& box) const {
     const Tensor<DataMesh> rho_i=
                           box.Get<Tensor<DataMesh> >(mInput);
     const MyVector<DataMesh>& coords=
                           box.Get<MyVector<DataMesh> >("GlobalCoords");
     const Mesh mesh = box.Get<Mesh>("Mesh");

     Tensor<DataMesh> rho_f(0, "", mesh); 
     Tensor<DataMesh> theta(0, "", mesh);  
     Tensor<DataMesh> phi(0, "", mesh);
    

     std::cout<<"**********I'm here!**********" ;
     theta(0) = acos(coords[0][2] / sqrt(coords[0][0]*coords[0][0] + 
                coords[0][1]*coords[0][1] + coords[0][2]*coords[0][2]));
     
     phi(0) = atan(coords[0][1] / coords[0][0]);
     

     Tensor<DataMesh> SHY(SphericalHarmonicYTDM(l, m, theta, phi)); 
    
     std::cout<<"Rank of rho_i: "<<rho_i.Rank()<<"\n";
     std::cout<<"Rank of rho_f: "<<rho_f.Rank()<<"\n";
     std::cout<<"Rank of theta: "<<theta.Rank()<<"\n";
     std::cout<<"Rank of phi: "<<phi.Rank()<<"\n";
     std::cout<<"Rank of SHY: "<<SHY.Rank()<<"\n";

     mResult.assign(0, "", mesh, rho_i(0)*SHY(0)); 
 
    /* for(int i = 0; i < rho_i(0).Size(); i++){
        mResult(0) = rho_i(0) * SHY(0);
     }     
     for(int i = 0; i < rho_i.Rank(); i++){
       rho_f(0)[i] = rho_i(0)[i]* SHY(0)[i];
     }*/ 
  
  }
}
