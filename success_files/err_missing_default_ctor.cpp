
namespace cwg257 {
  struct A { A(int); }; // #cwg257-A
  struct B : virtual A {
    B() : A(0) {}
    virtual void f() = 0;
  };
  struct D : B {
    D() {} // expected-error {{constructor for 'cwg257::D' must explicitly initialize the base class 'A' which does not have a default constructor}}
    void f() {}
  };
}
