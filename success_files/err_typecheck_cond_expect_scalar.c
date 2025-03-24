
void func_18(void) {
  struct S { int a; } s;
  struct T { int a; };
  (void)(_Atomic struct T)s; // expected-error {{used type 'struct T' where arithmetic or pointer type is required}}
}
