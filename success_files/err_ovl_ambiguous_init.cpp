
struct S {
  S(int, double);
  S(double, int);
};

void test() {
  (void)new S(1, 1); // expected-error {{call to constructor of 'S' is ambiguous}}
}
