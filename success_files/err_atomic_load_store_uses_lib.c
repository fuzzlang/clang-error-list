
struct foo {
  int big[128];
};

struct bar {
  char c[3];
};

struct bar smallThing;
struct foo bigThing;
_Atomic(struct foo) bigAtomic;

void structAtomicStore(void) {
  struct foo f = {0};
  __c11_atomic_store(&bigAtomic, f, 5); // expected-error {{atomic store requires runtime support that is not available for this target}}
}
