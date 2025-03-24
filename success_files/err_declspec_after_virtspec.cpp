
struct Base {
    virtual void f() = 0;
};

struct Derived : Base {
    virtual void f() override final const volatile; // expected-error {{'const' qualifier may not appear after the virtual specifier 'final'}} expected-error {{'volatile' qualifier may not appear after the virtual specifier 'final'}}
};
