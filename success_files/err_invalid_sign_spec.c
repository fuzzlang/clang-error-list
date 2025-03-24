
void foo() {
    signed auto a = 1L; // expected-error {{'auto' cannot be signed or unsigned}}
}
