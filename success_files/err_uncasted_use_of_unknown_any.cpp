
namespace test1 {
  extern __unknown_anytype foo;
  int test() {
    int x = foo; // expected-error {{'foo' has unknown type}}
    return 0;
  }
}
