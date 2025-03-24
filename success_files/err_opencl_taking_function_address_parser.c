
void foo() {}

int main() {
  // expected-error@-1 {{pointers to functions are not allowed}}
  foo((void*)foo);
  return 0;
}
