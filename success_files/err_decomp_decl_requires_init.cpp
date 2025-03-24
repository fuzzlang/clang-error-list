
int main() {
    auto [e][1]; // expected-error {{requires an initializer}}
    return 0;
}
