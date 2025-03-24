
// expected-error@+1 {{streaming function cannot be multi-versioned}}
__attribute__((target_version("sme2")))
void cannot_work_version(void) __arm_streaming {};
