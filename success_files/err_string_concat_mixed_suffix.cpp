
void operator""_℮""_ℯ(unsigned long long) {} // expected-error {{differing user-defined suffixes ('_℮' and '_ℯ') in string literal concatenation}}

int main() {
  "test"_℮"string"_ℯ; // triggers the expected error
  return 0;
}
