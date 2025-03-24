
struct B {
  ~B() noexcept(false) {}
};

void test() {
  throw B();  // expected-error{{cannot throw object of type 'B' with a potentially-throwing destructor}}
}
