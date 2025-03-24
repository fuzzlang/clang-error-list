
void test() {
  // expected-error@+1{{unexpected argument 'value' to '#pragma clang fp eval_method'; expected 'source', 'double' or 'extended'}}
  #pragma clang fp eval_method(value)
  int x = 0;
}
