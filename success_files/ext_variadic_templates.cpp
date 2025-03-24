
#if __cplusplus >= 201103L
  auto b({1, 2}); // expected-error@-2 {{initializer for variable 'b' with type 'auto' contains multiple expressions}}
  auto c({});
  // since-cxx11-error@-1 {{cannot deduce type for variable 'c' with type 'auto' from parenthesized initializer list}}
  auto d({1});
  // since-cxx11-error@-1 {{cannot deduce type for variable 'd' with type 'auto' from parenthesized initializer list}}
  auto e({1, 2});
  // since-cxx11-error@-1 {{cannot deduce type for variable 'e' with type 'auto' from parenthesized initializer list}}
#endif
  template<typename...Ts> void f(Ts ...ts) {
  }
