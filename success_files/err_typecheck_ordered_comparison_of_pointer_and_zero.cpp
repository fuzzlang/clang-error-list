
namespace cwg583 { // cwg583: 4
  int *p;

  void checkPointerComparison() {
    bool b1 = p < 0; // expected-error{{comparison between pointer and integer}}
  }
}
