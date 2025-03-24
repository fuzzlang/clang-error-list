
namespace test8 {
  template<typename T> struct A {
    int n = A{}.n; // expected-error {{default member initializer for 'n' uses itself}} expected-note {{instantiation of default member init}}
  };
  A<int> ai = {}; // expected-note {{instantiation of default member init}}
}
