
namespace cwg1918 { // cwg1918: no
template<typename T> struct A {
  class B {
    class C {};
  };
};
class X {
  static int x;
  // expected-error@-1 {{member 'D' has the same name as its class}}
  template <typename T>
  friend class A<T>::B::C;
};
template<> struct A<int> {
  typedef struct Q B;
};
struct Q {
  class C {
    int member; // This will trigger the expected error
    int f() { return X::x; }
  };
};
} // namespace cwg1918

namespace cwg1940 { // cwg1940: 3.5
#if __cplusplus >= 201103L
static union {
  static_assert(true, "");  // ok
  static_assert(false, "");  // expected-error@-1 {{static assertion failed}}
  int not_empty;
};
#endif
}

namespace cwg1947 { // cwg1947: 3.5
#if __cplusplus >= 201402L
unsigned o = 0'01;  // ok
unsigned b = 0b'01; // expected-error@-1 {{invalid digit 'b' in number}}
#endif
}
