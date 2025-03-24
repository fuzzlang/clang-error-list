
namespace cwg25 { // cwg25: yes
  struct A {
    void f() throw(int);
    // since-cxx17-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
    //   since-cxx17-note@-2 {{use 'noexcept(false)' instead}}
  };

  void (A::*f)() throw(int); // expected-error@-1 {{ISO C++17 does not allow dynamic exception specifications}} 
                              //   expected-note@-2 {{use 'noexcept(false)' instead}}

  void (A::*g)() throw() = f; // expected-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
                              //   expected-note@-2 {{use 'noexcept(false)' instead}}
}
