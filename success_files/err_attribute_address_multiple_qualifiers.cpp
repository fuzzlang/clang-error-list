
int __attribute__((address_space(1))) __attribute__((address_space(2))) * Y;  // expected-error {{multiple address spaces specified for type}}
