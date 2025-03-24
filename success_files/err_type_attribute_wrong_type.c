
int i __arm_inout("za"); // expected-error {{'__arm_inout' only applies to function types}}

void example() {
    int j = 0;
    j __arm_inout("za"); // expected-error {{'__arm_inout' only applies to function types}}
}
