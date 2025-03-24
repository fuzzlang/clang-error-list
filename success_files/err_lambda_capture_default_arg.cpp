
const int global = 0;

void f2() {
  int i = 1;
  void g1(int = ([i]{ return i; })()); // expected-error{{lambda expression in default argument cannot capture any entity}}
}
