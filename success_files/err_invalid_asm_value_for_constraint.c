
void I(int i, int j) {
    static const int BelowMin = -1;
    __asm__("xorl %0,%2"
            : "=r"(i)
            : "0"(i), "I"(BelowMin)); // expected-error{{value '-1' out of range for constraint 'I'}}
}
