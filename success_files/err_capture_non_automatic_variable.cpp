
struct S {
    int a;
};

void enclosing() {
    static auto [m] = S(); // expected-note {{'m' declared here}} \\
    struct R { int f() { return m.a; } };
    (void)[m]{}; // expected-error {{'m' cannot be captured because it does not have automatic storage duration}}
}
