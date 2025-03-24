
void test() {
    int a = 10;
    auto f = [x... = a]{}; // expected-error {{must appear before the name}}
}
