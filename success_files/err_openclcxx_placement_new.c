
class A {
  public:
  A() : x(21) {}
  int x;
};

typedef __SIZE_TYPE__ size_t;

class B {
  public:
  B() : bx(42) {}
  void *operator new(size_t);
  void operator delete(void *ptr);
  int bx;
};

// Test that clang rejects these gracefully.
void test_default_new_delete(void *buffer, A **pa) {
  *pa = new (buffer) A; // expected-error {{use of placement new requires explicit declaration}}
}
