
__builtin_va_list ap;

struct Foo {
  // expected-error@+1 {{default argument references parameter 'a'}}
  void meth(int a, int b = (__builtin_va_start(ap, a), 0)) {}
};
