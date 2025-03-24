
namespace cwg21 { // cwg21: 3.4
  template<typename T> struct A;
  struct X {
    template<typename T = int> friend struct A;
    // expected-error@-1 {{default template argument not permitted on a friend template}}
  };
}
