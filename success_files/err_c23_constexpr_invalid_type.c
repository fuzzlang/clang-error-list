
constexpr int a = 0; // c17-error {{unknown type name 'constexpr'}} \
                        c23-warning {{'constexpr' is incompatible with C standards before C23}}

void func(int array[constexpr]); // c23-error {{expected expression}} \
                                 // c17-error {{use of undeclared}}

_Atomic constexpr int b = 0; // c23-error {{constexpr variable cannot have type 'const _Atomic(int)'}} 
