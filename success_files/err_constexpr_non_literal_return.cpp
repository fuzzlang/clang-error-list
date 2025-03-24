
namespace cwg1358 { // cwg1358: 3.1
#if __cplusplus >= 201103L
  struct Lit { constexpr operator int() const { return 0; } };
  struct NonLit { NonLit(); operator int(); };

  template<typename T, typename U, typename V> struct A : V {
    int member;
    constexpr A(U u) : member(u) {}
    constexpr T f(U u) const { return T(); }
  };

  constexpr A<Lit, Lit, Lit> ce = Lit();
  constexpr int k = ce.f(Lit{});

  A<NonLit, NonLit, NonLit> a = NonLit();
  void g() { 
    a.f(NonLit()); 
  }

  struct B {
    int member;
    constexpr B(NonLit u) : member(u) {}
    constexpr NonLit f(NonLit u) const { return NonLit(); } // expected-error@-1 {{constexpr function's return type 'NonLit' is not a literal type}}
  };
#endif
} // namespace cwg1358
