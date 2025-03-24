
void test() {
  (void)new int[2000000000]; // expected-error {{array is too large}}
}
