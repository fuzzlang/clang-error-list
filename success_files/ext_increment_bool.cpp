
#if __cplusplus >= 201703L
  // expected-error@-2 {{ISO C++17 does not allow incrementing expression of type bool}}
#endif

void test() {
  bool b = true; // Initialization required
  ++b; // expected-error {{increment of boolean expression}}
}
