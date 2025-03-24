
namespace cwg127 {
  template<typename T>
  struct A {
    void operator delete(void *) { T::error; }
  };
  A<void> *p = new A<void>; // #cwg127-p
  A<int> *q = new ("") A<int>; // #cwg127-q
}

namespace cwg136 {
  void f(int, int, int = 0); // #cwg136-f
  void g(int, int, int); // #cwg136-g
  struct A {
    friend void f(int, int = 0, int); // expected-error@#cwg136-f {{error: friend function declaration with default argument re-declared}}
  };
}
