
void foo() {
    _Float16 a; // declaration of a variable of type _Float16
    (void)__builtin_complex(a, a); // expected-error {{'_Complex _Float16' is invalid}}
}
