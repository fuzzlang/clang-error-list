
namespace cwg478 {
  struct A { virtual void f() = 0; }; // #cwg478-f
  void f(A *a);
  void f(A a[10]); // expected-error {{array of abstract class type}}
}
