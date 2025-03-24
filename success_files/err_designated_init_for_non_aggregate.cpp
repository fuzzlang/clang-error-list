
namespace no_unwrap {
  template<typename T> struct X {
    static_assert(false, "should not be instantiated");
  };
  struct Q {
    template<typename T, typename U = typename X<T>::type> Q(T&&);
  };

  void g() {
    Q q = {.a = 1}; // expected-error {{initialization of non-aggregate type 'Q' with a designated initializer list}}
  }
}
