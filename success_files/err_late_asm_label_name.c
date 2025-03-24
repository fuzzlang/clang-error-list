
// RUN: %clang_cc1 -verify %s

void f(void);
void f(void) __asm__("fish");
void g(void);

void f(void) {
    g();
}

void g(void) __asm__("gold");  // expected-error{{cannot apply asm label to function after its first use}}
