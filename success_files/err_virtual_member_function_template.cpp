
struct S {
    template <class C>
    virtual void g(C); // expected-error{{'virtual' cannot be specified on member function templates}}
};
