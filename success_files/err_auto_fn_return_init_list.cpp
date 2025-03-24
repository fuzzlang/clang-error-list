
auto func() {
    return { 1, 2, 3 }; // expected-error {{cannot deduce return type from initializer list}}
}
