
namespace cwg480 {
  class B {};
  class D : public virtual B {};

  void foo() {
    D d;
    B *b = (B *)&d; // expected-error@-1 {{cannot cast 'A' to 'D &' via virtual base 'cwg480::B'}}
  }
}

namespace cwg481 { // cwg481: 2.8
  template<class T, T U> class A { T *x; };
  B *x; // This will reference the class B but is incorrect in context
}
