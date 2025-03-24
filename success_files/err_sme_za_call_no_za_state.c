
void sme_arm_shared_za(void) __arm_inout("za");

void example() {
  // expected-error@+2 {{call to a shared ZA function requires the caller to have ZA state}}
  // expected-cpp-error@+1 {{call to a shared ZA function requires the caller to have ZA state}}
  sme_arm_shared_za();
}
