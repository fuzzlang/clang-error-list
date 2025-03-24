
void std_example() {
    const int y = 999;
    char c3{y};  // expected-error {{cannot be narrowed}} expected-note {{silence}} expected-warning {{changes value}}
}
