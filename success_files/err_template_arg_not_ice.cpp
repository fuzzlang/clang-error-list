
#if __cplusplus == 199711L
#define static_assert(...) __extension__ _Static_assert(__VA_ARGS__)
// cxx98-error@-1 {{variadic macros are a C99 feature}}
#endif

namespace cwg2007 { // cwg2007: 3.4
template<typename T> struct A { typename T::error e; };
template<typename T> struct B { };
B<A<void> > b1;
B<A<void> > b2 = b1;
int a = b2[0];
// cxx98-error@-1 {{type 'B<A<void> >' does not provide a subscript operator}}
// since-cxx11-error@-2 {{type 'B<A<void>>' does not provide a subscript operator}}
int b = __builtin_addressof(b2)->foo;
// cxx98-error@-1 {{no member named 'foo' in 'cwg2007::B<cwg2007::A<void> >'}}
// since-cxx11-error@-2 {{no member named 'foo' in 'cwg2007::B<cwg2007::A<void>>'}}
}

namespace cwg2026 { // cwg2026: 11
  template<int> struct X {};

  const int a = a + 1; // #cwg2026-a
  // expected-warning@-1 {{variable 'a' is uninitialized when used within its own initialization}}
  X<a> xa; // #cwg2026-xa
}
