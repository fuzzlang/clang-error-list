
struct Base {
    virtual void func() {}
};

struct Derived : virtual Base {
    int data[]; // expected-error {{flexible array member 'data' not allowed in struct which has a virtual base class}}
};
