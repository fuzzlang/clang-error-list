
void test_atomic_builtin(_BitInt(42) *ptr, int value) {
  __sync_fetch_and_add(ptr, value); // expected-error {{atomic memory operand must have a power-of-two size}}
}
