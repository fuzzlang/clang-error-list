
// expected-error@-1 {{type 'int' cannot be used prior to '::' because it has no members}}
//   expected-note@#cwg289-C-int {{in instantiation of template class 'cwg289::C<int>' requested here}}
struct C {
  // Intentionally left empty
};

struct D : C<int> {}; // #cwg289-C-int

namespace cwg294 { // cwg294: no
  void f() throw(int);
  // since-cxx17-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
  //   since-cxx17-note@-2 {{use 'noexcept(false)' instead}}
  
  int main() {
    (void)static_cast<void (*)() throw()>(f); // FIXME: ill-formed in C++14 and before
    // FIXME: since-cxx17-error@-1 {{static_cast from 'void (*)() throw(int)' to 'void (*)() throw()' is not allowed}}
    
    (void)static_cast<void (*)() throw(int)>(f); // FIXME: ill-formed in C++14 and before
    // since-cxx17-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
    //   since-cxx17-note@-2 {{use 'noexcept(false)' instead}}

    void (*p)() throw() = f;
    // cxx98-14-error@-1 {{target exception specification is not superset of source}}
    // since-cxx17-error@-2 {{cannot initialize a variable of type 'void (*)() throw()' with an lvalue of type 'void () throw(int)': different exception specifications}}
    void (*q)() throw(int) = f;
    // since-cxx17-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
    //   since-cxx17-note@-2 {{use 'noexcept(false)' instead}}
  }
}

namespace cwg295 { // cwg295: 3.7
  typedef int f();
  const f g;
  // expected-warning@-1 {{'const' qualifier on function type 'f' (aka 'int ()') has no effect'}}
  
  f &r = g;
  
  template<typename T> struct X {
    const T &f;
  };
  X<f> x = {g};

  typedef int U();
  typedef const U U;
  // expected-warning@-1 {{'const' qualifier on function type 'U' (aka 'int ()') has no effect'}}

  typedef int (*V)();
  typedef volatile U *V;
  // expected-warning@-1 {{'volatile' qualifier on function type 'U' (aka 'int ()') has no effect}}
}

namespace cwg296 { // cwg296: yes
  struct A {
    static operator int() { return 0; }
  };
}
