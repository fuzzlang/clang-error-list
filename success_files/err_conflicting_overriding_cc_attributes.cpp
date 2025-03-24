
struct Base {
    virtual void f(); // default calling convention is thiscall
};

struct Derived : Base {
    void __attribute__((cdecl)) f() override; // expected-error{{virtual function 'f' has different calling convention attributes ('void () __attribute__((cdecl))') than the function it overrides (which has calling convention 'void () __attribute__((thiscall))')}}
};
