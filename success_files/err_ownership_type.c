
void f10(int i) __attribute__((ownership_holds(foo, 1)));  // expected-error {{'ownership_holds' attribute only applies to pointer arguments}}

void f11(int* p) {
    // Function implementation
}
