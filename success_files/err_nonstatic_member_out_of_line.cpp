
struct A2 {
  struct RC {
    int x; // expected-error{{non-static data member defined out-of-line}}
  };
};

int A2::RC::x; // expected-error{{non-static data member defined out-of-line}}
