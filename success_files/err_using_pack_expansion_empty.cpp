
template<typename ...T> struct S : T... {
  using T::h ...; // expected-error {{member using declaration 'h' instantiates to an empty pack}}
  void f(int n, int m) { h(n, m); }
};

void test() {
  S<> s;
  s.f(1, 2);
}
