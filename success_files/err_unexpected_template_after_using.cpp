
// RUN: %clang_cc1 %s -verify

namespace N1 {
template <typename... Ts>
struct Foo {
  template <typename T>
  struct Bar {
    static constexpr bool is_present = false;
  };
};

template <typename T, typename... Ts>
struct Foo<T, Ts...> : public Foo<Ts...> {
  using template Foo<Ts...>::Bar; // expected-error {{unexpected template name after 'using'}}
};
}
