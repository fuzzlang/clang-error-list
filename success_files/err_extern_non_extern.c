
void f(int x) { // expected-note {{previous definition is here}}
  extern int x; // expected-error {{extern declaration of 'x' follows non-extern declaration}}
}
