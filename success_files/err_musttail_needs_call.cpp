
int ReturnsInt1();

int Func1() {
  [[clang::musttail]] return 5; // expected-error {{'musttail' attribute requires that the return value is the result of a function call}}
}
