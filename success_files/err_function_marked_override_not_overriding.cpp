
struct Base {
    virtual void f(int); // Notice it's an int, not long
};

struct Derived : Base {
    virtual void f(long) override; // expected-error {{'f' marked 'override' but does not override any member functions}}
};
