
static const int x = 10; // Example variable initialization

static const int test0 = __builtin_omp_required_simd_align(x); // expected-error {{invalid application of '__builtin_omp_required_simd_align' to an expression, only type is allowed}}
