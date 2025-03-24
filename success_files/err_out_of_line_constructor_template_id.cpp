
namespace cwg145 { // cwg145: yes
  void f(bool b) {
    ++b;
    // cxx98-14-warning@-1 {{incrementing expression of type bool is deprecated and incompatible with C++17}}
    // since-cxx17-error@-2 {{ISO C++17 does not allow incrementing expression of type bool}}
    b++;
    // cxx98-14-warning@-1 {{incrementing expression of type bool is deprecated and incompatible with C++17}}
    // since-cxx17-error@-2 {{ISO C++17 does not allow incrementing expression of type bool}}
  }
}

namespace cwg147 { // cwg147: yes
  namespace example1 {
    template<typename> struct A {
      template<typename T> A(T);
    };
    // expected-error@-1 {{use of undeclared identifier 'f'}}
    template<> template<> A<int>::A<int>(int) {}
  }
}
