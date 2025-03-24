
namespace cwg470 {
  template<typename T> struct A {
    struct B {};
  };
  template<typename T> struct C {
  };

  template struct A<int>; // #cwg470-A-int
  template struct A<int>::B;

  template struct C<int>::B; // expected-error{{implicit instantiation of undefined template}}
}
