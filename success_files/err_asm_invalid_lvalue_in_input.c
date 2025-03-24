
void test4(int *addr) {
    asm ("nop" : : "m"(test4(addr))); // expected-error {{invalid lvalue in asm input for constraint 'm'}}
}
