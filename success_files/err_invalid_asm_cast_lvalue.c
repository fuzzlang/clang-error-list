
void test() {
    int a;
    asm("nop" : : "m"((int)(a))); // expected-error {{cast in a inline asm context requiring an lvalue}}
}
