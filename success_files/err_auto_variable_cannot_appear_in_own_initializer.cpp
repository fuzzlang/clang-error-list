
int main() {
    auto n = n; // expected-error {{variable 'n' declared with deduced type 'auto' cannot appear in its own initializer}}
    return 0;
}
