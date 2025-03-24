
namespace pr5900 {
  struct NotAnArray {};
  void test0() {
    NotAnArray x;
    x[0]; // expected-error {{does not provide a subscript operator}}
  }

  struct NonConstArray {
    int operator[](unsigned); // expected-note {{candidate}}
  };
  
  int test1() {
    const NonConstArray x = NonConstArray();
    return x[0]; // expected-error {{no viable overloaded operator[] for type}}
  }
}
