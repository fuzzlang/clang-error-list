
void example_function() {
    __builtin_va_arg((void*){0}, int); // expected-error {{first argument to 'va_arg' is of type 'void *'}}
}
