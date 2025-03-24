
struct S {
    int a;
    int b;
    int c;
};

int main() {
    for (; auto [a, b, c] = S(); ) {} // expected-warning {{ISO C++17 does not permit structured binding declaration in a condition}} expected-error {{value of type 'S' is not contextually convertible to 'bool'}}
}
