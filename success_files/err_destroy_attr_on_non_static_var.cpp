
void test() {
  [[clang::no_destroy]] int q; // expected-error{{no_destroy attribute can only be applied to a variable with static or thread storage duration}}
}
