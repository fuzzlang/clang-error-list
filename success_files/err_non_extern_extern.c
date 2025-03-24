
void f2(void) {
  extern int g8; // expected-note{{previous declaration}}
  int g8; // expected-error {{non-extern declaration of 'g8' follows extern declaration}}
}
