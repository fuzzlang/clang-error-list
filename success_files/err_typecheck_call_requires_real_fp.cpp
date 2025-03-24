
void foo() {
    double v = 1.0;
    int d = 2;
    (void)__builtin_complex(v, d); // expected-error {{different types}} expected-error {{not a real floating}}
}
