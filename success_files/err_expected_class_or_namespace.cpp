
namespace DecltypeAutoShouldNotBeADecltypeSpecifier {
  namespace NNS {
    int n;
    decltype(auto) i();
    decltype(n) j(); // expected-error {{not a class}}
    struct X {
      friend decltype(auto) ::DecltypeAutoShouldNotBeADecltypeSpecifier::NNS::i();
      friend decltype(n) ::DecltypeAutoShouldNotBeADecltypeSpecifier::NNS::j(); // expected-error {{not a class}}
    };
  }
}
