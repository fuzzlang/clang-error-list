
namespace test1 {
  void foo() {
    class A {
      friend void bar(); // expected-error {{no matching function found in local scope}}
    };
  }
}
