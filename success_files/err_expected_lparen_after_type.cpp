
struct Base {};
struct Derived : Base {
    Derived(int, Base) {}
};

template <typename T>
T load() {
    return T{};
}

struct Array1 {};
struct Mask {};

Base* foo(Array1 mask) {
    return new Derived{load<Array1>(), Mask{}}; // expected-error {{expected '(' after type name}} 
}
