
namespace test0 {
  void dummy() {
    void Bar(); // expected-note {{'Bar' declared here}}
    class A {
      friend void bar(); // expected-error {{no matching function 'bar' found in local scope; did you mean 'Bar'}}
    };
  }
}
