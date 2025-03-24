
void test20(void) {
  int n = 7;
  int vla[n]; // expected-note {{declared here}}
  ^{
    (void)vla[1];  // expected-error {{cannot refer to declaration with a variably modified type inside block}}
  }();
}
