
struct A {
  void a_member();
  friend void A::a_member();
};

UndeclaredSoFar x; // expected-error {{unknown type name 'UndeclaredSoFar'}}

void A::a_member() {}
