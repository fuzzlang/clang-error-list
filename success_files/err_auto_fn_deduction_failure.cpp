
auto *ptr_1() {
  return 100; // expected-error {{cannot deduce return type 'auto *' from returned value of type 'int'}}
}
