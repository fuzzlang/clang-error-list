
namespace cwg641 {
  struct A {
    int x;
  };

  void f(const A &a) {
    (void)A();
    (void)ca; // expected-error@-1 {{no matching function for call to 'f'}}
      // expected-note@#cwg641-f {{candidate function not viable: 1st argument ('const A') would lose const qualifier}}
  }

  const A *ca = nullptr; // Necessary variable initialization
}

namespace cwg642 { // cwg642: yes
  void f() {
    const int i = 2;
    {
      char i[i];
      static_assert(sizeof(i) == 2, "");
    }
  }

  struct s { int a; };
  void g(int s) {
    struct s *p = new struct s;
    p->a = s;
  }
}

#if __cplusplus >= 201103L
namespace cwg643 { // cwg643: 3.2
  struct A {
    int x;
    auto f() -> decltype(this->x);
    auto f(A &a) -> decltype(a.x);
    auto g() -> decltype(x);
    auto h() -> decltype(this->y);
    // since-cxx11-error@-1 {{no member named 'y' in 'cwg643::A'}}
    auto h(A &a) -> decltype(a.y);
    // since-cxx11-error@-1 {{no member named 'y' in 'cwg643::A'}}
    auto i() -> decltype(y);
    // since-cxx11-error@-1 {{use of undeclared identifier 'y'}}
    int y;
  };
}
#endif

#if __cplusplus >= 201103L
namespace cwg644 { // cwg644: partial
  struct A {
    A() = default;
    int x, y;
  };
  static_assert(__is_literal_type(A), "");

  struct B : A {};
  static_assert(__is_literal_type(B), "");

  struct C : virtual A {};
  static_assert(!__is_literal_type(C), "");

  struct D { C c; };
  static_assert(!__is_literal_type(D), "");

  template<typename T>
  struct E : T {
    constexpr E() = default;
  };
  static_assert(!__is_literal_type(E<C>), "");
}
#endif

#if __cplusplus >= 201103L
namespace cwg646 { // cwg646: sup 981
  struct A {
    constexpr A(const A&) = default; // ok
  };

  struct B {
    constexpr B() {}
    B(B&);
  };
  constexpr B b = {}; // ok
}
#endif

#if __cplusplus >= 201103L
namespace cwg647 { // cwg647: 3.1
  struct A {
    constexpr virtual void f() const;
    constexpr virtual void g() const {}
  };
}
#endif
