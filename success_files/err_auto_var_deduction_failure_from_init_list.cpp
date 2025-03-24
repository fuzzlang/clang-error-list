
struct X {};

void foo() {
    auto X::*x = { X() }; // expected-error {{from initializer list}}
}
