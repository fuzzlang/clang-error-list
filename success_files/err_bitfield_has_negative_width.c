
struct a {
  int a : -1; // expected-error{{bit-field 'a' has negative width}}
};
