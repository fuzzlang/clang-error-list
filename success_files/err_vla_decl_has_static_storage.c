
void foo() {
  int n = 10;
  static int fine[n]; // expected-error {{variable length array declaration cannot have 'static' storage duration}}
}
