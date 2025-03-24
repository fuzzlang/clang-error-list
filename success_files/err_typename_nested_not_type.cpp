
namespace example {
  struct A {
    struct X {};
    int X;
  };

  template <class T>
  void f(T t) {
    typename T::X x; 
    // expected-error {{typename specifier refers to non-type member 'X' in 'example::A'}}
  }

  void test() {
    A a;
    f(a); // trigger instantiation
  }
}
