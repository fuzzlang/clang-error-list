
void fn1(void) {
    int l;
    __asm__("" 
            : [l] "=r"(l) 
            : "[l],m"(l)); // expected-error {{asm constraint has an unexpected number of alternatives: 1 vs 2}}
}
