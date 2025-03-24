
// Test case to reproduce no previous prototype error

#pragma clang diagnostic error "-Weverything" // Set to error
void ppr(void) {} // expected-error {{no previous prototype for function 'ppr'}}
