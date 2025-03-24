
void shared_za_def() __arm_inout("za") { } // expected-error {{function using ZA state requires 'sme'}}
