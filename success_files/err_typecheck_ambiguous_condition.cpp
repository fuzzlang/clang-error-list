
namespace cwg241 {
  template <int N>
  void f() {}

  void test() {
    int b = 0; // Necessary initialization for 'b'
    f<3>(b); // expected-error@-1 {{no matching function for call to 'f'}}
    //   expected-note@#cwg241-C-f {{candidate template ignored: invalid explicitly-specified argument for template parameter 'T'}}
    //   expected-note@#cwg241-A-f {{candidate function template not viable: requires 0 arguments, but 1 was provided}}
  }
}

namespace cwg243 { // cwg243: yes
  struct B;
  struct A {
    A(B); // #cwg243-A
  };
  struct B {
    operator A() = delete; // #cwg243-B
    // cxx98-error@-1 {{deleted function definitions are a C++11 extension}}
  } b;
  A a1(b);
  A a2 = b; // cxx98-error@-1 {{deleted function definitions are a C++11 extension}}
}
