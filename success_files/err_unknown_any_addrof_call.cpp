
namespace test6 {
  extern __unknown_anytype func();
  double *d;

  void test() {
    d = (double*)&func(); // expected-error{{address-of operator cannot be applied to a call to a function with unknown return type}}
  }
}
