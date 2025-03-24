
namespace test3 {
  extern __unknown_anytype foo;
  void test() {
    foo(); // expected-error {{call to unsupported expression with unknown type}}
  }
}
