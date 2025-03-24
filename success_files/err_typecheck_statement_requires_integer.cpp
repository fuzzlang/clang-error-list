
struct S {
    int x;
    int y;
    int z;
};

void test() {
    switch (auto [a, b, c] = S{}) {} // expected-warning {{ISO C++17 does not permit structured binding declaration in a condition}} expected-error {{statement requires expression of integer type ('S' invalid)}}
}
