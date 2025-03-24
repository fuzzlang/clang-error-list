
#ifdef __ARM_FP
__attribute__((interrupt("IRQ"))) void callee(void) {}

void caller(void) {
    callee(); // expected-error {{interrupt service routine cannot be called directly}}
}
#endif // __ARM_FP
