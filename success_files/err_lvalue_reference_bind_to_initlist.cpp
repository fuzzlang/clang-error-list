
struct S {
  int a, b, c;
};

void test() {
  S& r3 = { 1, 2, 3 };  // expected-error {{non-const lvalue reference to type 'S' cannot bind to an initializer list temporary}}
}
