
typedef unsigned int u_int32_t;
typedef u_int32_t uint32_t;
typedef unsigned long long u_int64_t;
typedef u_int64_t uint64_t;
typedef float __m128 __attribute__ ((vector_size (16)));
typedef float __m256 __attribute__ ((vector_size (32)));
typedef float __m512 __attribute__ ((vector_size (64)));

__m128 val128;
__m256 val256;
__m512 val512;

int func1(void) {
    uint32_t msr = 0x8b;
    uint64_t val = 0;
    __asm__ volatile("wrmsr"
                     :
                     : "c" (msr),
                       "a" ((val & 0xFFFFFFFFUL)), // expected-error {{invalid input size for constraint 'a'}}
                     "d" (((val >> 32) & 0xFFFFFFFFUL)));
}
