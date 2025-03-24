
struct A {
    A() [[clang::lifetimebound]]; // expected-error {{cannot be applied to a constructor}}
};

A::A() {}
