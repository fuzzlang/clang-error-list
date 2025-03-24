
void someFunction() {
    global int L4;  // expected-error{{function scope variable cannot be declared in global address space}}
}
