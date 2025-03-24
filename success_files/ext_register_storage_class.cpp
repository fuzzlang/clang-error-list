
void stuff(register int q) { // expected-error@-4 {{ISO C++17 does not allow dynamic exception specifications}} expected-note@-4 {{use 'noexcept(false)' instead}}
    // Some implementation
}
