
// expected-error@+1 {{conflicting attributes for state 'za'}}
void conflicting_state_attrs_in_out(void) __arm_in("za") __arm_out("za");
