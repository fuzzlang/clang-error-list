
void share_zt0_only() __arm_inout("zt0");

void unimplemented_spill_fill_za(void (*share_zt0_only)(void) __arm_inout("zt0")) __arm_inout("za", "zt0") {
    // expected-error@+2 {{call to a function that shares state other than 'za' from a function that has live 'za' state requires a spill/fill of ZA, which is not yet implemented}}
    // expected-note@+1 {{add '__arm_preserves("za")' to the callee if it preserves ZA}}
    share_zt0_only();
}
