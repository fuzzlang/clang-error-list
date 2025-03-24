
class X {};

void test() {
  X x;
  x.operator typedef; // expected-error{{expected a type}} expected-error{{type name does not allow storage class}}
}

void test2() {
  X *x;
  x->operator typedef; // expected-error{{expected a type}} expected-error{{type name does not allow storage class}}
}
