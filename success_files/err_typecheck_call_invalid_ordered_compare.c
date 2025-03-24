
int test1(float a, int b) {
  return __builtin_isless(a, b);
}

int test2(int a, int b) {
  return __builtin_islessequal(a, b);  // expected-error {{floating point type}}
}
