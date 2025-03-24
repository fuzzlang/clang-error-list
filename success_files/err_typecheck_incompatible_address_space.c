
typedef int ASInt __attribute__((address_space(1)));

int main() {
  int int_value = 42;
  ASInt *as_int_ptr1 = &int_value;  // expected-error{{changes address space of pointer}}
  return 0;
}
