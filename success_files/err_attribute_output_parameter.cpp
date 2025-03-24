
void g(int a __attribute__((acquire_handle("Fuchsia")))); // expected-error {{attribute only applies to output parameters}}

void test() {
    g(5);
}
