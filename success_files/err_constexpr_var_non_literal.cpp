
namespace cwg1573 {
#if __cplusplus >= 201103L
  struct A { A(); };
  struct C { C(); constexpr C(int) {} };
  struct E : C { using C::C; A a; }; // #cwg1573-E
  constexpr E e = E(0);
// expected-error {{constexpr variable cannot have non-literal type 'const E'}}
// note: 'E' is not literal because it has a data member 'a' of non-literal type 'A'
#endif
}
