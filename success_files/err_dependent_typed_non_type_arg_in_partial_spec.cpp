
namespace DefaultArgVsPartialSpec {
  template<typename T, int N = sizeof(T)> struct X {};
  template<typename T> struct X<T> {};

  template<typename T, T N = 0> struct S;
  template<typename T> struct S<T> {}; // expected-error {{non-type template argument specializes a template parameter with dependent type 'T'}}
}
