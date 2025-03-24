
namespace nondeducible {
  template<typename A, typename B> struct X {};

  template<typename A> // expected-note {{non-deducible template parameter 'A'}}
  X() -> X<A, int>; // expected-error {{deduction guide template contains a template parameter that cannot be deduced}}
}
