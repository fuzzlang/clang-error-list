
namespace N1 {
  struct A {
    template<int I>
    void f();
  };

  template<typename T>
  struct B {
    A x;
    A g();

    void not_instantiated(B *a, B &b) {
      g().f<0>(); // expected-error{{missing 'template' keyword prior to dependent template name 'f'}}
    }
  };
} // namespace N1
