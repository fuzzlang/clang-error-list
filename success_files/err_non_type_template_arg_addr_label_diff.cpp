
template<typename T, T val> struct A {};

namespace LabelAddrDiff {
  void f() {
    a: 
    b: 
    A<int, __builtin_constant_p(true) ? (__INTPTR_TYPE__)&&b - (__INTPTR_TYPE__)&&a : 0> s; // expected-error {{label address difference}}
  }
}
