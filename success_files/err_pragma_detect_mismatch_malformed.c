
void example() {
#pragma detect_mismatch("test") // expected-error {{pragma detect_mismatch is malformed; it requires two comma-separated string literals}}
}
