
struct X {
  void f(int x = 1:); // expected-error {{unexpected end of default argument expression}}
};
