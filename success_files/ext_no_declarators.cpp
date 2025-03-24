
#if __cplusplus >= 201103L
  struct X { constexpr X() = default; union {}; };  // expected-error@-1 {{declaration does not declare anything}}
#endif
