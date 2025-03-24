
namespace PR88832 {
template <typename T> struct O {
  static const T v = 0;
};

struct P {
  template <typename T> using I = typename O<T>::v; // #TypeAlias
};

struct Q {
  template <typename T> int foo() {
    return T::template I<int>; // expected-error {{'P::I' is expected to be a non-type template, but instantiated to a type alias template}}
  }
};

int bar() {
  return Q().foo<P>(); // expected-note {{function template specialization requested here}}
}
} // namespace PR88832
