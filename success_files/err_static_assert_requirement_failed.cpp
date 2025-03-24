
template <typename T>
struct A {
    constexpr int f() const {
        return 2; // Any value other than 1 will cause the static_assert to fail
    }
};

int main() {
    static_assert(A<int>().f() == 1); // expected-error {{static assertion failed}}
    return 0;
}
