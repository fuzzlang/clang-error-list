
void checkAvailability() {
    (void)__builtin_available(); // expected-error{{expected a platform name here}}
}
