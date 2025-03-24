
void test21(void) {
  int a[7]; // expected-note {{declared here}}
  __block int b[10]; // expected-note {{declared here}}
  a[1] = 1;
  ^{ 
    (void)a[1]; // expected-error {{cannot refer to declaration with an array type inside block}}
    (void)b[1]; // expected-error {{cannot refer to declaration with an array type inside block}}
  }();
}
