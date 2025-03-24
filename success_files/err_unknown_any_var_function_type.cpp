
namespace test3 {
  extern __unknown_anytype foo;
  void test() {
    ((void(void)) foo)(); // expected-error {{variable 'foo' with unknown type cannot be given a function type}}
  }
}
