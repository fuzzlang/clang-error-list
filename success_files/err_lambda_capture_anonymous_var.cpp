
namespace ImplicitCapture {
  void test() {
    union {
      int c; // expected-note {{declared}}
      float d;
    };
    [=]() { return c; }; // expected-error {{unnamed variable cannot be implicitly captured in a lambda expression}}
  }
}
