
struct S {
   S (S);  // expected-error {{copy constructor must pass its first argument by reference}}
};

class foo {
public:
  foo(foo&, int = 0) { } // expected-error {{makes this constructor a copy constructor}}
};

namespace PR6064 {
  struct A {
    inline A(A&, int); // expected-note {{previous}}
  };

  A::A(A&, int = 0) { } // expected-error {{makes this constructor a copy constructor}}
}

namespace PR10618 {
  struct C {
    C(const C&, int); // expected-note {{previous}}
  };
  C::C(const C&,
       int = 0) { // expected-error {{makes this constructor a copy constructor}}
  }
}
