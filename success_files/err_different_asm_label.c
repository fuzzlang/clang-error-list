
void f(void) __asm__("fish");
void g(void);

void f(void) {
  g();
}

void h(void) __asm__("hose");  // expected-note{{previous declaration is here}}
void h(void) __asm__("hair");  // expected-error{{conflicting asm label}}
