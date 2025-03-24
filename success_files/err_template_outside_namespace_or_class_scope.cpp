
namespace PR46859 {
  extern "bogus" // expected-error {{unknown linkage language}}
    template<int> struct X {}; // expected-error {{templates can only be declared in namespace or class scope}}
}
