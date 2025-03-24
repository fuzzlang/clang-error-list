
// expected-error@+2 {{cannot redeclare builtin function '__builtin_va_copy'}}
// expected-note@+1 {{'__builtin_va_copy' is a builtin with type}}
void __builtin_va_copy(int a);
