
void test() {
    for (void f() : "error") { // expected-error {{for range declaration must declare a variable}}
    }
}
