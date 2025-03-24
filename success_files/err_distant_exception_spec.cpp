
namespace cwg90 { // cwg90: no
  void g(); // Declaration of 'g'
  void f() {
    g(); // expected-error@-1 {{use of undeclared identifier 'cwg90_g'}}
  }
}

namespace cwg91 { // cwg91: yes
  union U { friend int f(U); };
  int k = f(U());
}

namespace cwg92 { // cwg92: 4 c++17
  void f() throw(int, float);
  // since-cxx17-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
  //   since-cxx17-note@-2 {{use 'noexcept(false)' instead}}
  void (*p)() throw(int) = &f; // #cwg92-p
  // since-cxx17-error@#cwg92-p {{ISO C++17 does not allow dynamic exception specifications}}
  //   since-cxx17-note@#cwg92-p {{use 'noexcept(false)' instead}}
  // cxx98-14-error@#cwg92-p {{target exception specification is not superset of source}}
  // since-cxx17-warning@#cwg92-p {{target exception specification is not superset of source}}
  void (*q)() throw(int);
  // since-cxx17-error@-1 {{ISO C++17 does not allow dynamic exception specifications}}
  //   since-cxx17-note@-2 {{use 'noexcept(false)' instead}}
  void (**pp)() throw() = &q;
}
