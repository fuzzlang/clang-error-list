
struct Base {
    int a;
    Base(int val) : a(val) {}
};

struct Derived : Base {
    void f() : a(242) { } // expected-error{{only constructors take base initializers}}
};
