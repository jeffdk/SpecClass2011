#include "ComputeQ_danh.hpp"
#include "Utils/StringParsing/OptionParser.hpp"

namespace ComputeItems {
  
  ComputeQ_danh::ComputeQ_danh(const std::string& opts): 
    mResult(3, "1", DataMesh::Empty) {
    OptionParser p(opts, Help()); 
    mOutput = p.Get<std::string>("Output");
  }
  
  void ComputeQ_danh::RecomputeData(const DataBoxAccess& box) const {
    const MyVector<DataMesh>& x = box.Get<MyVector<DataMesh> >("GlobalCoords");

    const DataMesh R = sqrt(x[0]*x[0]+x[1]*x[1]+x[2]*x[2]);
    Tensor<DataMesh> Q(3,"l",R);
    int i=0;
    for(TensorIter it(Q); it; ++it) {

        Q[it] = x[i]/(R*R*R);
        ++i;
    }

    //EvaluateScalarFormula(                                                   
    //    Output=Radius;                                                       
    //    Formula=sqrt(x0*x0+x1*x1+x2*x2);                                     
    //),                                                                       
    //EvaluateVectorFormula(                                                   
    //    R=Radius;                                                            
    //    V[0]=x0/(R*R*R);                                                     
    //    V[1]=x1/(R*R*R);                                                     
    //    V[2]=x2/(R*R*R);                                                     
    //    Output=Q;                                                            
    //),             

    //ASSERT_TensorStructure(Q, 3, "1");
    mResult = Q;
  }

} 
