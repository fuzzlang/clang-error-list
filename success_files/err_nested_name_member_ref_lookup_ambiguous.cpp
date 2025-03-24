
namespace A {
  namespace B {
    struct base {
      void x() {}
    };
  }

  struct sub : B::base {};

  struct member {
    void foo();
  };
}

void fun4a() {
  A::sub *a;

  typedef A::member base;
#if __cplusplus <= 199711L
  // expected-note@-2 {{lookup from the current scope refers here}}
#endif
  a->base::x();
#if __cplusplus <= 199711L
  // expected-error@-2 {{lookup of 'base' in member access expression is ambiguous}}
#endif
}
