
namespace cwg671 { // cwg671: 2.9
  enum class E { e };
  // cxx98-error@-1 {{scoped enumerations are a C++11 extension}}
  E e = static_cast<E>(0);
  int n = static_cast<int>(E::e); // expected-error@-1 {{use of enumeration in a nested name specifier is a C++11 extension}}
}
