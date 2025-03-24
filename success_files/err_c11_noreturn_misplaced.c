
struct s; // expected-note{{previous use is here}}
union s *s1; // expected-error{{use of 's' with tag type that does not match previous declaration}}

struct Point {
  float x, y, z;
};

struct Point *get_origin(void);

void test_point(void) {
  (void)get_origin->x; // expected-error {{base of member reference is a function; perhaps you meant to call it with no arguments?}}
}

// These errors require C11.
#if __STDC_VERSION__ > 199901L
void noreturn_1(void) _Noreturn; // expected-error {{must precede function declarator}}
void noreturn_1(void) {
  return; // expected-warning {{should not return}}
}
#endif
