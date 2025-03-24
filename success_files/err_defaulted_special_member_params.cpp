
struct A {
    A(double = 0.0) = default; // expected-error {{cannot have default arguments}}
};
