
int j;

void foo(void) {
  ^ (void) { if (j) return 1; }(); // expected-error {{non-void block does not return a value in all control paths}}
}
