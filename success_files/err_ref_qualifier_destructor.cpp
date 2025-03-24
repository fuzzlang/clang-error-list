
struct X {
  ~X() &; // expected-error{{ref-qualifier '&' is not allowed on a destructor}}
};
