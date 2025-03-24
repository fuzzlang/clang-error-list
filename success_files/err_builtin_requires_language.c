
void function() {
    __builtin_operator_new(0); // expected-error {{'__builtin_operator_new' is only available in C++}}
}
