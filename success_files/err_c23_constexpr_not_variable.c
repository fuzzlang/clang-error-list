
constexpr void f0() {} // expected-error {{'constexpr' can only be used in variable declarations}}

int main() {
    return 0;
}
