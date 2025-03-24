
namespace cwg284 {
  struct D {
    struct W {};
    struct X {}; // expected-error@-1 {{no struct named 'V' in 'cwg284::D'}}
    enum Y { e2 }; // ok per cwg417
    class Z {}; // ok per cwg417
  };
}

namespace cwg285 {
  template<typename T> void f(T, int); // #cwg285-f-T-int
  template<typename T> void f(int, T); // #cwg285-f-int-T
  template<> void f<int>(int, int) {};
}
