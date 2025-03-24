
namespace Curried {
  template<typename T, typename U> struct S;
  template<typename T> template<typename U> using SS = S<T, U>; // expected-error {{extraneous template parameter list in alias template declaration}}
}
