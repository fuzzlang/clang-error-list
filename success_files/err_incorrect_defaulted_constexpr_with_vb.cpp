
struct Base {
    constexpr Base() = default;
};

struct Derived : virtual Base { // expected-note {{virtual base class declared here}}
    constexpr Derived() = default; // expected-error {{default constructor cannot be 'constexpr' in a class with virtual base class}}
};
