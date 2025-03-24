
void func() {
    unsigned long long v;
    __builtin_arm_wsr64("sysreg", v); // expected-error {{invalid special register for builtin}}
}
