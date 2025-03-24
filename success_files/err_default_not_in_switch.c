
void f(int z) {
  while (z) {
    default: z--; // all-error {{'default' statement not in switch}}
  }
}

_Static_assert(&c != 0, ""); // ref-warning {{always true}} \
                             // pedantic-ref-warning {{always true}} \
                             // pedantic-ref-warning {{is a GNU extension}} \
                             // expected-warning {{always true}} \
                             // pedantic-expected-warning {{always true}} \
                             // pedantic-expected-warning {{is a GNU extension}}
_Static_assert(&a != 0, ""); // ref-warning {{always true}} \
                             // pedantic-ref-warning {{always true}} \
                             // pedantic-ref-warning {{is a GNU extension}} \
                             // expected-warning {{always true}} \
                             // pedantic-expected-warning {{always true}} \
                             // pedantic-expected-warning {{is a GNU extension}}

extern int a; // Declaration for 'a'
extern int c; // Declaration for 'c'

_Static_assert((&c + 1) != 0, ""); // pedantic-ref-warning {{is a GNU extension}} \
                                   // pedantic-expected-warning {{is a GNU extension}}
_Static_assert((&a + 100) != 0, ""); // pedantic-ref-warning {{is a GNU extension}} \
                                     // pedantic-ref-note {{100 of non-array}} \
                                     // pedantic-expected-note {{100 of non-array}} \
                                     // pedantic-expected-warning {{is a GNU extension}}
_Static_assert((&a - 100) != 0, ""); // pedantic-ref-warning {{is a GNU extension}} \
                                     // pedantic-expected-warning {{is a GNU extension}} \
                                     // pedantic-ref-note {{-100 of non-array}} \
                                     // pedantic-expected-note {{-100 of non-array}}

struct Test50S {
    int x;
};

extern struct Test50S Test50;
_Static_assert(&Test50 != (void*)0, ""); // all-warning {{always true}} \
                                         // pedantic-warning {{is a GNU extension}} \
                                         // pedantic-note {{this conversion is not allowed in a constant expression}}

struct y {int x, y;};
int a2[(intptr_t)&((struct y*)0)->y]; // all-warning {{folded to constant array}}

const struct y *yy = (struct y*)0;
const intptr_t L = (intptr_t)(&(yy->y)); // all-error {{not a compile-time constant}}

_Static_assert((long)&((struct y*)0)->y > 0, ""); // pedantic-ref-warning {{GNU extension}} \
                                                  // pedantic-ref-note {{this conversion is not allowed in a constant expression}} \
                                                  // pedantic-expected-warning {{GNU extension}} \
                                                  // pedantic-expected-note {{this conversion is not allowed in a constant expression}}

const ptrdiff_t m = &m + 137 - &m;
_Static_assert(m == 137, ""); // pedantic-ref-warning {{GNU extension}} \
                              // pedantic-expected-warning {{GNU extension}}
