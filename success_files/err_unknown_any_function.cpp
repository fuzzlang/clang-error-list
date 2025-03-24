
namespace test4 {
  extern __unknown_anytype test1(...);

  void test() {
    int x = (int) test1; // expected-error {{function 'test1' with unknown type must be given a function type}}
  }
}
