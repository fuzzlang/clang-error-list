
namespace cwg50 {
  template<int*> struct A {}; // #cwg50-A
  int k;
#if __has_feature(cxx_constexpr)
  constexpr
#endif
  int *const p = &k; // #cwg50-p
  A<&k> a;
  A<p> b; // expected-error@-1 {{redefinition of 'f'}}
  void f(); // #cwg50-f
  void g() { f(); }
}
