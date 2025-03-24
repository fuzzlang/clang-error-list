
struct X {
    void ref() & {}
    void cref() const& {}
    void cvref() const volatile & {}
};

void test() {
    (X{}.*&X::ref)(); // expected-error-re{{pointer-to-member function type 'void (X::*)() {{.*}}&' can only be called on an lvalue}}
}
