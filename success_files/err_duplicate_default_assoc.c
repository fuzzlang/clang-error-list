
void foo(void) {
    (void) _Generic(0,
        default: 0,  // expected-note {{previous default generic association is here}}
        default: 0); // expected-error {{duplicate default generic association}}
}
