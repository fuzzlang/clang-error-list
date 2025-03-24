
void example() {
    (void)__exception_info();  // expected-error{{only allowed in __except filter expression}}
}
