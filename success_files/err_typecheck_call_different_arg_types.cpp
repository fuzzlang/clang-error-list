
template<typename T>
void test_builtin_complex(T v, double d) {
    (void)__builtin_complex(v, d); // expected-error {{different types}} expected-error {{not a real floating}}
}

template void test_builtin_complex(double, double);
template void test_builtin_complex(float, double); // expected-note {{instantiation of}}
template void test_builtin_complex(int, double); // expected-note {{instantiation of}}
