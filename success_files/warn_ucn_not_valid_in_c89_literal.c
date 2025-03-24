
void function() {
    (void)L"\u1234";  // expected-error {{universal character names are only valid in C99 or C++}}
}
