
struct X {};
using PX = std::pair<X, X>;
using PI = std::pair<int, int>;

namespace sad {
  template<typename T> void swap(T &, T &);

  template<typename A, typename B> struct CLASS {
    void swap(CLASS &other) noexcept(noexcept(swap(*this, other))); // expected-error {{too many arguments}} expected-note {{declared here}}
  };

  CLASS<int, int> pi;

  static_assert(!noexcept(pi.swap(pi)), ""); // expected-note 2{{in instantiation of exception specification for 'swap'}}
}
