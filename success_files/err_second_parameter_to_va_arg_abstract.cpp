
struct Abstract {
  virtual void func() = 0; // Abstract method
};

void testVaArg() {
  __builtin_va_list list;
  (void)__builtin_va_arg(list, Abstract); // expected-error{{second argument to 'va_arg' is of abstract type 'Abstract'}}
}
