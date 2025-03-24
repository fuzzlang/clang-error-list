
void testFunction() {
    if (decltype(auto) b) {} // expected-error {{must have an initializer}}
}
