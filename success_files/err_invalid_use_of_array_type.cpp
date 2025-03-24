
struct X {
    bool flag;
    int data;
    constexpr explicit operator bool() const {
        return flag;
    }
    constexpr operator int() const {
        return data;
    }
};

namespace CondInIf {
constexpr char g(char const (&x)[2]) {
    if (auto [a, b] = x) // expected-error {{an array type is not allowed here}}
        ;
}
static_assert(g("x") == 'x');
} // namespace CondInIf
