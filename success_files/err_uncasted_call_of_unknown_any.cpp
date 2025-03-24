
namespace test2 {
  extern __unknown_anytype foo(); 
  void test() {
    foo(); // expected-error {{'foo' has unknown return type}}
  }
}
