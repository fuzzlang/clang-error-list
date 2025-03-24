
struct A {
    auto operator=(const A&) = default; // expected-error {{must return 'A &'}}
};
