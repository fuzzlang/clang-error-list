
void func() {
    auto [a] = a; // expected-error {{binding 'a' cannot appear in the initializer of its own decomposition declaration}}
}
