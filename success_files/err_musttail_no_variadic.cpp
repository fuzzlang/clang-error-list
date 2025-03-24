
[[clang::musttail]] int VariadicFunction(int x, ...) {
    return x;
}

int main() {
    [[clang::musttail]] return VariadicFunction(10); // expected-error {{'musttail' attribute may not be used with variadic functions}}
}
