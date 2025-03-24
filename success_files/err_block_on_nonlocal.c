
// Attempting to apply __block attribute on a non-local variable
__attribute__((__blocks__(byref))) int *globalVar; // expected-error {{__block attribute not allowed, only allowed on local variables}}

void function() {
    __attribute__((__blocks__(byref))) int localVar = 0; // Correct usage
}
