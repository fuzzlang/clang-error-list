
struct Base {
    virtual int f(); // Base class function
};

struct Derived : Base {
    auto f(); // expected-error {{different return}}
};
