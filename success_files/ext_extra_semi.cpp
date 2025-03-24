
struct A {
    void i() = delete;;; // expected-error {{extra ';' after member function definition}}
};
