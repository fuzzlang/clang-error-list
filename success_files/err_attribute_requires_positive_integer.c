
// expected-error@+1 {{'patchable_function_entry' attribute requires a non-negative integral compile time constant expression}}
__attribute__((patchable_function_entry(-1))) void f(void) {}
