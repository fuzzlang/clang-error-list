
int t16; // non-thread-local declaration
__thread int t16; // expected-error {{thread-local declaration of 't16' follows non-thread-local declaration}}
