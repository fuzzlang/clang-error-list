
#if __aarch64__
#define VALID_DATA_KEY 2
#endif

struct A {
    int x;
} mismatched_type;

void test() {
    __builtin_ptrauth_strip(mismatched_type, VALID_DATA_KEY); // expected-error {{signed value must have pointer type; type here is 'struct A'}}
}
