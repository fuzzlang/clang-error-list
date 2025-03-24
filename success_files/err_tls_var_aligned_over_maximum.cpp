
struct alignas(64) aligned_struct {
  int data;
};

__thread aligned_struct bar; // expected-error{{alignment (64) of thread-local variable}}
