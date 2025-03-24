
void kernel foo(int x) {
    if (true) {
        local int L1; // expected-error {{variables in the local address space can only be declared in the outermost scope of a kernel function}}
    }
}
