
namespace cwg1 {
  // expected-error@-1 {{redefinition of default argument}}
  //   expected-note@#cwg1-z {{previous definition is here}}
  
  void i(int = 1);
  void j() {
    void i(int = 1);
    using cwg1::i;
    i(0);
    // FIXME: This should be rejected, due to the ambiguous default argument.
    i();
  }
  void k() {
    using cwg1::i;
    void i(int = 1);
    i(0);
    // FIXME: This should be rejected, due to the ambiguous default argument.
    i();
  }
}

namespace cwg3 { // cwg3: yes
  template<typename T> struct A {};
  template<typename T> void f(T) { A<T> a; } // #cwg3-f-T
  template void f(int);
  template<> struct A<int> {};
}
