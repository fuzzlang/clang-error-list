
template<int operator+> struct B {
    void foo() {}
}; // expected-error {{'operator+' cannot be the name of a parameter}}
