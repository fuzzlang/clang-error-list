
void foo(int param) {
    int var = 0;

    {
        auto lambda = [param](int param) { ; }; // expected-error {{a lambda parameter cannot shadow an explicitly captured entity}}
    }
}
