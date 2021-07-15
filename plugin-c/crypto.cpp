// #include <cryptopp/keccak.h>
// #include <cryptopp/ripemd.h>
// #include <cryptopp/sha.h>
// #include <cryptopp/sha3.h>
#include <secp256k1_recovery.h>
// #include <libff/algebra/curves/alt_bn128/alt_bn128_pp.hpp>
// #include <libff/common/profiling.hpp>
#include <openssl/evp.h>
#include "blake2.h"
#include "bls.h"
#include "plugin_util.h"

// using namespace CryptoPP;
// using namespace libff;

extern "C" {

struct string *hook_KRYPTO_sha512raw(struct string *str) {
  return NULL;
  // SHA512 h;
  // unsigned char digest[64];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return raw(digest, sizeof(digest));
}

struct string *hook_KRYPTO_sha512(struct string *str) {
  return NULL;
  // SHA512 h;
  // unsigned char digest[64];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return hexEncode(digest, sizeof(digest));
}

void sha512_256(struct string *input, unsigned char *result) {
  // EVP_MD_CTX *ctx = EVP_MD_CTX_new();
  // bool success = ctx != NULL                                 \
  //     && EVP_DigestInit_ex(ctx, EVP_sha512_256(), NULL) == 1 \
  //     && EVP_DigestUpdate(ctx, input->data, len(input)) == 1 \
  //     && EVP_DigestFinal_ex(ctx, result, NULL) == 1;
  // if (! success) throw std::runtime_error("openssl sha512_256 EVP_Digest runtime error");
  // EVP_MD_CTX_free(ctx);
}

struct string *hook_KRYPTO_sha512_256raw(struct string *str) {
  return NULL;
  // unsigned char digest[32];
  // sha512_256(str, digest);
  // return raw(digest, sizeof(digest));
}

struct string *hook_KRYPTO_sha512_256(struct string *str) {
  return NULL;
  // unsigned char digest[32];
  // sha512_256(str, digest);
  // return hexEncode(digest, sizeof(digest));
}

struct string *hook_KRYPTO_sha3raw(struct string *str) {
  return NULL;
  // SHA3_256 h;
  // unsigned char digest[32];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return raw(digest, sizeof(digest)); 
}

struct string *hook_KRYPTO_sha3(struct string *str) {
  return NULL;
  // SHA3_256 h;
  // unsigned char digest[32];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return hexEncode(digest, sizeof(digest));
}

struct string *hook_KRYPTO_keccak256raw(struct string *str) {
  return NULL;
  // Keccak_256 h;
  // unsigned char digest[32];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return raw(digest, sizeof(digest)); 
}

struct string *hook_KRYPTO_keccak256(struct string *str) {
  return NULL;
  // Keccak_256 h;
  // unsigned char digest[32];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return hexEncode(digest, sizeof(digest));
}

struct string *hook_KRYPTO_sha256raw(struct string *str) {
  return NULL;
  // SHA256 h;
  // unsigned char digest[32];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return raw(digest, sizeof(digest)); 
}

struct string *hook_KRYPTO_sha256(struct string *str) {
  return NULL;
  // SHA256 h;
  // unsigned char digest[32];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return hexEncode(digest, sizeof(digest));
}

struct string *hook_KRYPTO_ripemd160raw(struct string *str) {
  return NULL;
  // RIPEMD160 h;
  // unsigned char digest[20];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return raw(digest, sizeof(digest)); 
}

struct string *hook_KRYPTO_ripemd160(struct string *str) {
  return NULL;
  // RIPEMD160 h;
  // unsigned char digest[20];
  // h.CalculateDigest(digest, (unsigned char *)str->data, len(str));
  // return hexEncode(digest, sizeof(digest));
}

// matches evm and bitcoin's value of V, which is in the range 27-28
struct string *hook_KRYPTO_ecdsaRecover(struct string *str, mpz_t v, struct string *r, struct string *s) {
  return NULL;
  // if (len(str) != 32 || len(r) != 32 || len(s) != 32) {
  //   return hexEncode(nullptr, 0);
  // }
  // unsigned char sigArr[64];
  // memcpy(sigArr, r->data, 32);
  // memcpy(sigArr+32, s->data, 32);
  // secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
  // if (!mpz_fits_ulong_p(v)) {
  //   return hexEncode(nullptr, 0);
  // }
  // unsigned long v_long = mpz_get_ui(v);
  // if (v_long < 27 || v_long > 28) {
  //   return hexEncode(nullptr, 0);
  // }
  // secp256k1_ecdsa_recoverable_signature sig;
  // if (!secp256k1_ecdsa_recoverable_signature_parse_compact(ctx, &sig, sigArr, v_long - 27)) {
  //   return hexEncode(nullptr, 0);
  // }
  // secp256k1_pubkey key;
  // if (!secp256k1_ecdsa_recover(ctx, &key, &sig, (unsigned char *)str->data)) {
  //   return hexEncode(nullptr, 0);
  // }
  // unsigned char serialized[65];
  // size_t len = sizeof(serialized);
  // secp256k1_ec_pubkey_serialize(ctx, serialized, &len, &key, SECP256K1_EC_UNCOMPRESSED);
  // struct string *result = allocString(64);
  // memcpy(result->data, serialized+1, 64);
  // return result;
}

struct string *hook_KRYPTO_ecdsaSign(struct string *mhash, struct string *prikey) {
  return NULL;
  // if (len(prikey) != 32 || len(mhash) != 32) {
  //   return hexEncode(nullptr, 0);
  // }
  // secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  // secp256k1_ecdsa_recoverable_signature sig;
  // if (!secp256k1_ecdsa_sign_recoverable(ctx, &sig, (unsigned char *)mhash->data, (unsigned char *)prikey->data, NULL, NULL)) {
  //   return hexEncode(nullptr, 0);
  // }
  // unsigned char result[65];
  // int recid;
  // if (!secp256k1_ecdsa_recoverable_signature_serialize_compact(ctx, result, &recid, &sig)) {
  //   return hexEncode(nullptr, 0);
  // }
  // result[64] = recid;
  // return hexEncode(result, 65);
}

struct string *hook_KRYPTO_ecdsaPubKey(struct string *prikey) {
  return NULL;
  // if (len(prikey) != 32) {
  //   return hexEncode(nullptr, 0);
  // }
  // secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
  // secp256k1_pubkey pubkey;
  // if (!secp256k1_ec_pubkey_create(ctx, &pubkey, (unsigned char *)prikey->data)) {
  //   return hexEncode(nullptr, 0);
  // }
  // unsigned char keystring[65];
  // size_t outputlen = 65;
  // secp256k1_ec_pubkey_serialize(ctx, keystring, &outputlen, &pubkey, SECP256K1_EC_UNCOMPRESSED);
  // return hexEncode(keystring+1, outputlen-1);
}

struct string *hook_KRYPTO_blake2compress(struct string *params) {
    if (len(params) != 213) {
        return hexEncode(nullptr, 0);
    }
    unsigned char *data = (unsigned char *)params->data;
    uint32_t  rounds = data[0] << 24 | data[1] << 16 | data[2] << 8 | data[3];
    uint64_t *h      = (uint64_t *)&data[4];
    uint64_t *m      = (uint64_t *)&data[68];
    uint64_t *t      = (uint64_t *)&data[196];
    unsigned char f  = data[212];

    if (f > 1) return hexEncode(nullptr, 0);

    blake2b_compress(h, m, t, f, rounds);

    return hexEncode((unsigned char *)h, 64);
}

struct g1point {
  struct blockheader h;
  mpz_ptr x;
  mpz_ptr y;
};

struct g2point {
  struct blockheader h;
  mpz_ptr x0;
  mpz_ptr x1;
  mpz_ptr y0;
  mpz_ptr y1;
};

struct inj {
  struct blockheader h;
  void *data;
};

bool bn128_initialized = false;

extern "C++" {

static void initBN128() {
  if (bn128_initialized) {
    return;
  }
  // alt_bn128_pp::init_public_params();
  // inhibit_profiling_info = true;
  bn128_initialized = true;
}

// static alt_bn128_G1 getPoint(g1point *pt) {
//   if (mpz_cmp_ui(pt->x, 0) == 0 && mpz_cmp_ui(pt->y, 0) == 0) {
//     return alt_bn128_G1::zero();
//   }
//   mpz_t mod;
//   mpz_init(mod);
//   alt_bn128_Fq::mod.to_mpz(mod);
//   if (mpz_cmp(pt->x, mod) >= 0 || mpz_cmp(pt->y, mod) >= 0) {
//     throw std::invalid_argument("not a member of the field");
//   }
//   mpz_clear(mod);
//   auto x = bigint<alt_bn128_q_limbs>(pt->x);
//   auto y = bigint<alt_bn128_q_limbs>(pt->y);
//   auto z = bigint<alt_bn128_q_limbs>(1);
//   return alt_bn128_G1{x, y, z};
// }

// static alt_bn128_G2 getPoint(g2point *pt) {
//   if (mpz_cmp_ui(pt->x0, 0) == 0 && mpz_cmp_ui(pt->x1, 0) == 0 
//       && mpz_cmp_ui(pt->y0, 0) == 0 && mpz_cmp_ui(pt->y1, 0) == 0) {
//     return alt_bn128_G2::zero();
//   }
//   mpz_t mod;
//   mpz_init(mod);
//   alt_bn128_Fq::mod.to_mpz(mod);
//   if (mpz_cmp(pt->x0, mod) >= 0 || mpz_cmp(pt->x1, mod) >= 0
//       || mpz_cmp(pt->y0, mod) >= 0 || mpz_cmp(pt->y1, mod) >= 0) {
//     throw std::invalid_argument("not a member of the field");
//   }
//   mpz_clear(mod);
//   auto x = alt_bn128_Fq2{bigint<alt_bn128_q_limbs>(pt->x0), bigint<alt_bn128_q_limbs>(pt->x1)};
//   auto y = alt_bn128_Fq2{bigint<alt_bn128_q_limbs>(pt->y0), bigint<alt_bn128_q_limbs>(pt->y1)};
//   auto z = alt_bn128_Fq2::one();
//   return alt_bn128_G2{x, y, z};
// }

// static g1point *projectPoint(uint64_t hdr, alt_bn128_G1 pt) {
//   mpz_ptr x, y;
//   if (pt.is_zero()) {
//     x = (mpz_ptr) koreAllocInteger(0);
//     y = (mpz_ptr) koreAllocInteger(0);
//     mpz_init_set_ui(x, 0);
//     mpz_init_set_ui(y, 0);
//   } else {
//     pt.to_affine_coordinates();
//     x = (mpz_ptr) koreAllocInteger(0);
//     y = (mpz_ptr) koreAllocInteger(0);
//     mpz_init(x);
//     mpz_init(y);
//     pt.X.as_bigint().to_mpz(x);
//     pt.Y.as_bigint().to_mpz(y);
//   }
//   struct g1point *g1pt = (struct g1point *)koreAlloc(sizeof(struct g1point));
//   g1pt->h.hdr = hdr;
//   g1pt->x = x;
//   g1pt->y = y;
//   return g1pt;
// }
}

bool hook_KRYPTO_bn128valid(g1point *pt) {
  return true;
  // initBN128();
  // try {
  //   return getPoint(pt).is_well_formed();
  // } catch (std::invalid_argument) {
  //   return false;
  // }
}

// this code mirrors https://github.com/ethereum/aleth/blob/master/libdevcrypto/LibSnark.cpp
bool hook_KRYPTO_bn128g2valid(g2point *pt) {
  return true;
  // initBN128();
  // try {
  //   alt_bn128_G2 g2pt = getPoint(pt);
  //   return g2pt.is_well_formed() && -alt_bn128_G2::scalar_field::one() * g2pt + g2pt == alt_bn128_G2::zero();
  // } catch (std::invalid_argument) {
  //   return false;
  // }
}

g1point *hook_KRYPTO_bn128add(g1point *pt1, g1point *pt2) {
  initBN128();
  return pt1;
  // return projectPoint(pt1->h.hdr, getPoint(pt1) + getPoint(pt2));
}

g1point *hook_KRYPTO_bn128mul(g1point *pt, mpz_t scalar) {
  initBN128();
  return pt;
  // bigint<alt_bn128_q_limbs> s(scalar);
  // alt_bn128_G1 g1pt = getPoint(pt);
  // return projectPoint(pt->h.hdr, s * g1pt);
}

mpz_ptr hook_LIST_size(list *);
void *hook_LIST_get_long(list *, ssize_t);

bool hook_KRYPTO_bn128ate(list *g1, list *g2) {
  return true;
  // initBN128();
  // mpz_ptr g1size = hook_LIST_size(g1);
  // mpz_ptr g2size = hook_LIST_size(g2);
  // unsigned long g1size_long = mpz_get_ui(g1size);
  // unsigned long g2size_long = mpz_get_ui(g2size);
  // mpz_clear(g1size);
  // mpz_clear(g2size);
  // if (g1size_long != g2size_long) {
  //   throw std::invalid_argument("mismatched list sizes");
  // }
  // mpz_t bigi;
  // mpz_init(bigi);
  // alt_bn128_Fq12 accum = alt_bn128_Fq12::one();
  // for (unsigned long i = 0; i < g1size_long; i++) {
  //   inj *injg1 = (inj *)hook_LIST_get_long(g1, i);
  //   inj *injg2 = (inj *)hook_LIST_get_long(g2, i);
  //   alt_bn128_G1 g1pt = getPoint((g1point *)injg1->data);
  //   alt_bn128_G2 g2pt = getPoint((g2point *)injg2->data);
  //   if (g1pt.is_zero() || g2pt.is_zero()) {
  //     continue;
  //   }
  //   alt_bn128_Fq12 paired = alt_bn128_miller_loop(
  //       alt_bn128_precompute_G1(g1pt),
  //       alt_bn128_precompute_G2(g2pt));
  //   accum = accum*paired;
  // }
  // return alt_bn128_final_exponentiation(accum) == alt_bn128_GT::one();
}

//------------------------------------------------------------------------------
// compile with gcc -g crypto.cpp -o crypto -lpairing_plus_binding -L~/workspace/pairing-plus-binding/target/debug

typedef struct BLS12381FrPointKStruct {
  struct blockheader h;
  mpz_ptr a;
  mpz_ptr b;
  mpz_ptr c;
  mpz_ptr d;
} BLS12381FrPointK;
// typedef struct BLS12381FrPointCStruct {
//   unsigned long limbs[4];
// } BLS12381FrPointC;

typedef struct BLS12381FqPointKStruct {
  struct blockheader h;
  mpz_ptr a;
  mpz_ptr b;
  mpz_ptr c;
  mpz_ptr d;
  mpz_ptr e;
  mpz_ptr f;
} BLS12381FqPointK;
// typedef struct BLS12381FqPointCStruct {
//   unsigned long limbs[6];
// } BLS12381FqPointC;

// BLS12381FqPointC *K2C_BLS12381_Fq_Point(BLS12381FqPointK *p) {
//   BLS12381FqPointC *pp = (BLS12381FqPointC *)malloc(sizeof(BLS12381FqPointC));
//   pp->limbs[0] = mpz_get_ui(p->a);
//   pp->limbs[1] = mpz_get_ui(p->b);
//   pp->limbs[2] = mpz_get_ui(p->c);
//   pp->limbs[3] = mpz_get_ui(p->d);
//   pp->limbs[4] = mpz_get_ui(p->e);
//   pp->limbs[5] = mpz_get_ui(p->f);
//   return pp;
// }

// BLS12381FqPointK *C2K_BLS12381_Fq_Point(BLS12381FqPointC *p, uint64_t hdr) {
//   BLS12381FqPointK *pp = (BLS12381FqPointK *)koreAlloc(sizeof(BLS12381FqPointK));
//   pp->h.hdr = hdr;

//   mpz_ptr a, b, c, d, e, f;
//   a = (mpz_ptr) koreAllocInteger(0);
//   b = (mpz_ptr) koreAllocInteger(0);
//   c = (mpz_ptr) koreAllocInteger(0);
//   d = (mpz_ptr) koreAllocInteger(0);
//   e = (mpz_ptr) koreAllocInteger(0);
//   f = (mpz_ptr) koreAllocInteger(0);
//   // TODO: is this the correct way?
//   mpz_init_set_ui(a, p->limbs[0]);
//   mpz_init_set_ui(b, p->limbs[1]);
//   mpz_init_set_ui(c, p->limbs[2]);
//   mpz_init_set_ui(d, p->limbs[3]);
//   mpz_init_set_ui(e, p->limbs[4]);
//   mpz_init_set_ui(f, p->limbs[5]);
//   pp->a = a;
//   pp->b = b;
//   pp->c = c;
//   pp->d = d;
//   pp->e = e;
//   pp->f = f;
//   return pp;
// }

typedef struct BLS12381G1PointKStruct {
  struct blockheader h;
  BLS12381FqPointK *x;
  BLS12381FqPointK *y;
  BLS12381FqPointK *z;
} BLS12381G1PointK;
// typedef struct BLS12381G1PointCStruct {
//   BLS12381FqPointC x;
//   BLS12381FqPointC y;
//   BLS12381FqPointC z;
// } BLS12381G1PointC;

// BLS12381G1PointC *K2C_BLS12381_G1_Point(BLS12381G1PointK *p) {
//   BLS12381G1PointC *pp = (BLS12381G1PointC *)malloc(sizeof(BLS12381G1PointC));
//   pp->x = *(K2C_BLS12381_Fq_Point(p->x));
//   pp->y = *(K2C_BLS12381_Fq_Point(p->y));
//   pp->z = *(K2C_BLS12381_Fq_Point(p->z));
//   return pp;
// }

// BLS12381G1PointK *C2K_BLS12381_G1_Point(BLS12381G1PointC *p, uint64_t hdr) {
//   BLS12381G1PointK *pp = (BLS12381G1PointK *)koreAlloc(sizeof(BLS12381G1PointK));
//   pp->h.hdr = hdr;
//   pp->x = C2K_BLS12381_Fq_Point(&(p->x), hdr);
//   pp->y = C2K_BLS12381_Fq_Point(&(p->y), hdr);
//   pp->z = C2K_BLS12381_Fq_Point(&(p->z), hdr);
//   return pp;
// }

typedef struct BLS12381Fq2PointKStruct {
  struct blockheader h;
  BLS12381FqPointK *u;
  BLS12381FqPointK *v;
} BLS12381Fq2PointK;
// typedef struct BLS12381Fq2PointCStruct {
//   BLS12381FqPointC u;
//   BLS12381FqPointC v;
// } BLS12381Fq2PointC;

typedef struct BLS12381G2PointKStruct {
  struct blockheader h;
  BLS12381Fq2PointK *x;
  BLS12381Fq2PointK *y;
  BLS12381Fq2PointK *z;
} BLS12381G2PointK;
// typedef struct BLS12381G2PointCStruct {
//   BLS12381Fq2PointC x;
//   BLS12381Fq2PointC y;
//   BLS12381Fq2PointC z;
// } BLS12381G2PointC;


// extern BLS12381G1PointC rust_BLS12_G1ADD(BLS12381G1PointC p1, BLS12381G1PointC p2);
// extern BLS12381G1PointC rust_BLS12_G1MUL(BLS12381G1PointC *p1, BLS12381FrPointC *r1);
// extern BLS12381G1PointC rust_BLS12_G1MULTIEXP(unsigned long bases_len, unsigned long scalars_len, BLS12381G1PointC** c_bases, BLS12381FrPointC** scalars);
// extern BLS12381G2PointC rust_BLS12_G2ADD(BLS12381G2PointC *p1, BLS12381G2PointC *p2);

BLS12381G1PointK *hook_KRYPTO_bls12381g1add(BLS12381FqPointK *p1x, BLS12381FqPointK *p1y, BLS12381FqPointK *p1z,
                                            BLS12381FqPointK *p2x, BLS12381FqPointK *p2y, BLS12381FqPointK *p2z) {
  // BLS12381G1PointK *p1 = (BLS12381G1PointK *)malloc(sizeof(BLS12381G1PointK));
  // BLS12381G1PointK *p2 = (BLS12381G1PointK *)malloc(sizeof(BLS12381G1PointK));
  // p1->x = p1x;
  // p1->y = p1y;
  // p1->z = p1z;
  // p2->x = p2x;
  // p2->y = p2y;
  // p2->z = p2z;
  // BLS12381G1PointC *pp1 = K2C_BLS12381_G1_Point(p1);
  // BLS12381G1PointC *pp2 = K2C_BLS12381_G1_Point(p2);
  BLS12381G1PointC *pp1 = (BLS12381G1PointC *)malloc(sizeof(BLS12381G1PointC));
  BLS12381G1PointC *pp2 = (BLS12381G1PointC *)malloc(sizeof(BLS12381G1PointC));
  BLS12381G1PointC pp3 = c_rust_BLS12_G1ADD(*pp1, *pp2);
  // BLS12381G1PointK *p3 = C2K_BLS12381_G1_Point(&pp3, p1->h.hdr);
  // return p3;
  return NULL;
}

}
