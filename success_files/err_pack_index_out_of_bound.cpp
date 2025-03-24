
namespace GH88925 {
template <typename...> struct S {};

template <auto...> struct W {};

template <int...> struct sequence {};

template <typename... args, int... indices> auto f(sequence<indices...>) {
  return S<args...[indices]...>(); // expected-error {{invalid index 3 for pack 'args' of size 2}}
}

template <auto... args, int... indices> auto g(sequence<indices...>) {
  return W<args...[indices]...>(); // expected-error {{invalid index 4 for pack args of size 1}}
}

void h() {
  f<int, long>(sequence<3>()); // expected-error {{invalid index 3 for pack 'args' of size 2}}
  g<foo{}>(sequence<4>()); // expected-error {{invalid index 4 for pack args of size 1}}
}
}
