
struct Base {
    static void foo() {}
};

struct Derived : Base {};

int main() {
    // expected-error@+1 {{use of '__super' inside a lambda is unsupported}}
    auto lambda = []{ __super::foo(); };
    return 0;
}
