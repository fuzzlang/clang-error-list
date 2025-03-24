
void test() {
    #pragma GCC visibility pop // expected-error{{#pragma visibility pop with no matching #pragma visibility push}}
}
