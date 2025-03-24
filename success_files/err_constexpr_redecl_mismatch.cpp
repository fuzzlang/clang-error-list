
struct A {};
struct B { int n; }; // #cwg1460-B
struct C { int n = 0; };

struct X {
    friend constexpr A::A() noexcept; // no error expected here
    friend constexpr B::B() noexcept; // expected-error here
};
