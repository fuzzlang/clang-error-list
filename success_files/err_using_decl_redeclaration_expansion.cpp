
template<typename ...T> int fn1() {
  using T::e ...; // expected-error 2{{class member}} expected-note 2{{instead}}
  return e; // expected-error {{using declaration 'e' instantiates to an empty pack}}
}

namespace test_fn1 {
  struct X { static int e; };
  struct Y { typedef int e; };
  inline namespace P { enum E { e }; }
  inline namespace Q { enum F { e }; }
  void f() {
    fn1<>(); // expected-note {{instantiation of}}
    fn1<X>(); // expected-note {{instantiation of}}
    fn1<Y>(); // expected-note {{instantiation of}}
    fn1<E>();
    fn1<E, F>(); // expected-note {{instantiation of}}
    fn1<E, X>(); // expected-note {{instantiation of}}
  }
}
