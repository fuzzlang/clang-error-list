
void test() {
    // expected-error@-1 {{'B' is an incomplete type}}
    // expected-note@-2 {{forward declaration of 'B'}}
    (void)dynamic_cast<struct B{}*>(0);
}
