
void myFunction() {
#pragma clang assume_nonnull start // expected-error{{expected 'begin' or 'end'}}
    int *ptr = nullptr;
    *ptr = 42; // Use of null pointer
}
