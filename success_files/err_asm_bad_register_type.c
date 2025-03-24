
struct foo {
  int a;
};

register struct foo bar asm("esp"); // expected-error {{bad type for named register variable}}
