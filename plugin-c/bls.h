extern "C" {

typedef struct BLS12381FrPointCStruct {
  unsigned long limbs[4];
} BLS12381FrPointC;

typedef struct BLS12381FqPointCStruct {
  unsigned long limbs[6];
} BLS12381FqPointC;

typedef struct BLS12381G1PointCStruct {
  BLS12381FqPointC x;
  BLS12381FqPointC y;
  BLS12381FqPointC z;
} BLS12381G1PointC;

typedef struct BLS12381Fq2PointCStruct {
  BLS12381FqPointC u;
  BLS12381FqPointC v;
} BLS12381Fq2PointC;

typedef struct BLS12381G2PointCStruct {
  BLS12381Fq2PointC x;
  BLS12381Fq2PointC y;
  BLS12381Fq2PointC z;
} BLS12381G2PointC;

BLS12381G1PointC c_rust_BLS12_G1ADD(BLS12381G1PointC p1, BLS12381G1PointC p2);

}
