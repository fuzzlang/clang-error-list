
namespace cwg1653 { // cwg1653: 4 c++17
  void f(bool b) {
    ++b; // expected-error@-1 {{static assertion expression is not an integral constant expression}}
          //   expected-note@-2 {{comparison against pointer '&a + 1' that points past the end of a complete object has unspecified value}}
    b++;
    --b;
  }
}
