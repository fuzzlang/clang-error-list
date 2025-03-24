
// expected-error@-1 {{arithmetic on pointers to void}}
// FIXME: This is ill-formed.
template<void*> struct S;
template<int*> struct T;

namespace cwg574 { // cwg574: 3.0
  struct A {
    A &operator=(const A&) const; // #cwg574-A-copy-assign
  };
  struct B {
    B &operator=(const B&) volatile; // #cwg574-B-copy-assign
  };
#if __cplusplus >= 201103L
  struct C {
    C &operator=(const C&) &; // #cwg574-C-copy-assign
  };
  struct D {
    D &operator=(const D&) &&; // #cwg574-D-copy-assign
  };
  void test(C c, D d) {
    c = c;
    C() = c; // expected-error@-1 {{arithmetic on pointers to void}}
  }
#endif
}
