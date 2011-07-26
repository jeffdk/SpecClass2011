void Invert2x2matrix(const Tensor<DataMesh>& F, Tensor<DataMesh>& InvF) {
  
  REQUIRE(F.Rank()==2), "F must be second rank tensor")
  REQUIRE(F.Dim()==2), "F must be 2x2 matrix")

// (1)
  const DataMesh DetF = F(0,0)*F(1,1)-F(0,1)*F(1,0);

// (2)
DataMesh DetF(F(0,0), 0.0);
DetF = F(0,0)*F(1,1)-F(0,1)*F(1,0);

// (3)
DataMesh DetF(F(0,0) ); 
DetF = F(0,0)*F(1,1)-F(0,1)*F(1,0);


InvF(0,0) = F(1,1)/DetF;
InvF(0,1) = -F(0,1)/DetF;
InvF(1,1) = F(0,0)/DetF;
if(TensorStructure(F.Dim(),"11")!=F.Structure()) {
  InvF(1,0) = -F(1,0)/DetF;
 }
}
