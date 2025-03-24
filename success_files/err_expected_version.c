
int main() {
  __builtin_available(macos);  // expected-error{{expected a version}}
  return 0;
}
