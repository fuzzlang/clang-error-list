
kernel void f8(int a1) {
    int a2;
    void (^bl)(void) = ^(void) {
        &a1; // expected-error{{taking address of a capture is not allowed}}
    };
}
