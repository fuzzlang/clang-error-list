
struct B1 {
  void B1(int); // expected-error@-1 {{expected expression}}
};

struct B2 {
  explicit(false) explicit;
};
