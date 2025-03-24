
namespace cwg2644 { // cwg2644: 8
#if __cplusplus >= 201103L
auto z = [a = 42](int a) {
// expected-error@-1 {{initialized lambda captures are a C++14 extension}}
// since-cxx11-error@-2 {{a lambda parameter cannot shadow an explicitly captured entity}}
//   since-cxx11-note@-3 {{variable 'a' is explicitly captured here}}
     return 1;
};
#endif
}

#if __cplusplus >= 202302L
namespace cwg2650 { // cwg2650: 17
template <class T, T> struct S {};
template <class T> int f(S<T, T{}>*); // #cwg2650-f
class X {
  int m;
};
int i0 = f<X>(0);
// expected-error@-1 {{no matching function for call to 'f'}} 
//   expected-note@#cwg2650-f {{type 'X' of non-type template parameter is not a structural type}}
}
#endif

#if __cplusplus >= 202302L
namespace cwg2653 { // cwg2653: 18
  struct Test { void f(this const auto& = Test{}); };
  // expected-error@-1 {{the explicit object parameter cannot have a default argument}}
  auto L = [](this const auto& = Test{}){};
  // expected-error@-1 {{the explicit object parameter cannot have a default argument}}
}
#endif

namespace cwg2654 { // cwg2654: 16
void f() {
    int neck, tail;
    volatile int brachiosaur;
    brachiosaur += neck;                // OK
    brachiosaur -= neck;                // OK
    brachiosaur |= neck;                // OK
}
}

namespace cwg2681 { // cwg2681: 17
#if __cplusplus >= 202002L
using size_t = decltype(sizeof(int));

template<class T, size_t N>
struct H {
  T array[N];
};
template<class T, size_t N>
struct I {
  volatile T array[N];
};
template<size_t N>
struct J { // #cwg2681-J
  unsigned char array[N];
};

H h = { "abc" };
I i = { "def" };
static_assert(__is_same(decltype(h), H<char, 4>));  // Not H<const char, 4>
static_assert(__is_same(decltype(i), I<char, 4>));

J j = { "ghi" }; // expected-error@-1 {{no viable constructor}}
#endif
}
