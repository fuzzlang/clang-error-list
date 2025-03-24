
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
    C() = c;
    // since-cxx11-error@-1 {{no viable overloaded '='}}
    //   since-cxx11-note@#cwg574-C-copy-assign {{candidate function not viable: expects an lvalue for object argument}}
    d = d;
    // since-cxx11-error@-1 {{no viable overloaded '='}}
    //   since-cxx11-note@#cwg574-D-copy-assign {{candidate function not viable: expects an rvalue for object argument}}
    D() = d;
  }
#endif
  struct Test {
    friend A &A::operator=(const A&);
  };
  
  void function_with_error() {
    // This will trigger the expected error
    S<void*> s1; // expected-error {{arithmetic on pointers to void}}
    T<int*> t1; 
  }
}
