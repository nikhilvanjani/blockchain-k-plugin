#include "bls.h"

extern "C" {

extern BLS12381G1PointC rust_BLS12_G1ADD(BLS12381G1PointC p1, BLS12381G1PointC p2);
extern BLS12381G1PointC rust_BLS12_G1MUL(BLS12381G1PointC *p1, BLS12381FrPointC *r1);
extern BLS12381G1PointC rust_BLS12_G1MULTIEXP(unsigned long bases_len, unsigned long scalars_len, BLS12381G1PointC** c_bases, BLS12381FrPointC** scalars);
extern BLS12381G2PointC rust_BLS12_G2ADD(BLS12381G2PointC *p1, BLS12381G2PointC *p2);
}

BLS12381G1PointC c_rust_BLS12_G1ADD(BLS12381G1PointC p1, BLS12381G1PointC p2) {
	return rust_BLS12_G1ADD(p1, p2);
}

