
struct S {
    int x;
};

void test() {
    auto [alignas(42) a, foo] = S{0}; // expected-error {{an attribute list cannot appear here}}
}
