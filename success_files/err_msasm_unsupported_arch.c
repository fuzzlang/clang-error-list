
void test() {
    __asm nop; // expected-error {{unsupported architecture 'powerpc64' for MS-style inline assembly}}
}
