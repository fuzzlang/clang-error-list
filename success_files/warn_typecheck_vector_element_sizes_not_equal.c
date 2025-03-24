
#ifdef EXT
typedef __attribute__((__ext_vector_type__(8))) int vector_int8;
typedef __attribute__((__ext_vector_type__(8))) unsigned char vector_uchar8;
#else
typedef __attribute__((vector_size(32))) int vector_int8;
typedef __attribute__((vector_size(8))) unsigned char vector_uchar8;
#endif

vector_int8 vi8;
vector_uchar8 vuc8;

void foo(void) {
    vi8 = vi8 << vuc8; // expected-error {{vector operands do not have the same elements sizes}}
}
