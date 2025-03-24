
typedef int&& irr;

irr ret_irr() {
  return 0; // expected-warning {{returning reference to local temporary}}
}

void f() {
  const int ci1 = 1;
  (void)static_cast<int &&>(ci1);    // expected-error {{types are not compatible}}
}
