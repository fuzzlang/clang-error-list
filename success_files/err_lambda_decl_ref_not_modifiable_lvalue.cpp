
namespace ModifyingCapture {
  void test() {
    int n = 0;
    [=] { 
      n = 1; // expected-error {{cannot assign to a variable captured by copy in a non-mutable lambda}} 
    };
  }
}
