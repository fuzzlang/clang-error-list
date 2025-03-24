
template<int ...N>
void bad1() {
    (N + ... + N); // expected-error {{unexpanded parameter packs in both operands}}
}
