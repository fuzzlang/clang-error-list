
void test() {
  struct S { double x; } s;
  struct S *s1 = &s;
  __atomic_fetch_sub(s1, 3, __ATOMIC_SEQ_CST); // expected-error {{must be a pointer to integer, pointer or supported floating point type}}
}
