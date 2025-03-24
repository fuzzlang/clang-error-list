
void example() {
    __arm_inout("za") {} // expected-error {{'__arm_inout' cannot be applied to a statement}}
}
