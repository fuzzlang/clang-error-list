
#define _AS1 __attribute__((address_space(1)))

struct SomeStruct {
    int a;
    long b;
    int c;
};

void as_compound_literal(void) {
    (_AS1 struct SomeStruct){1, 2, 3}; // expected-error {{compound literal in function scope may not be qualified with an address space}}
}
