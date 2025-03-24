
struct A {
    constexpr A() {}
};

struct B : A {
    constexpr B() : {} // expected-error {{expected class member or base class name}}
};
