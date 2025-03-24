
typedef signed char v32i8 __attribute__((vector_size(32), aligned(32)));

v32i8 xvslli_b(v32i8 _1, int var) {
    v32i8 res = __builtin_lasx_xvslli_b(_1, -1); // expected-error {{argument value 4294967295 is outside the valid range [0, 7]}}
    return res;
}
