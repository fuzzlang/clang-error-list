
void inout_zt0_def() __arm_inout("zt0") { } // expected-error {{function using ZT0 state requires 'sme2'}}
