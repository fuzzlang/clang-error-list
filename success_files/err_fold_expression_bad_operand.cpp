
template<int ...N>
void bad2() {
    (2 * N + ... + 1); // expected-error {{expression not permitted as operand}}
}
