
struct B {
  B(B&);
  B &operator=(B&);
};

struct C : B {
  C(const C&) = default; // expected-error {{may not have 'const'}}
  C &operator=(const C&) const = default; // expected-error {{may not have 'const'}}
};
