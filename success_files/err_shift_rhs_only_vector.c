
void foo(void) {
    vector signed char sc;
    signed char sc_scalar;

    sc = sc_scalar << sc; // expected-error {{first operand is not a vector}}
}
