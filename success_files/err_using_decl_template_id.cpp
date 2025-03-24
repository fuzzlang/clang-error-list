
struct T {
    template <typename U>
    void f() {}
};

void example() {
    // expected-error@-1 {{'template' keyword not permitted here}}
    using T::template f<int>;
}
