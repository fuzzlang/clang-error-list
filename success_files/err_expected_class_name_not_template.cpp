
namespace PR11216 {
  template<typename T>
  struct Derived6 : typename T::foo { }; // expected-error {{'typename' is redundant; base classes are implicitly types}}
}
