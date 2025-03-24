
class A {
  void bar(int);
};

void bar(int, int);  // expected-note{{'::bar' declared here}}

void A::bar(int x) {
  bar(x, 5);  // expected-error{{too many arguments to function call, expected 1, have 2; did you mean '::bar'?}}
}
