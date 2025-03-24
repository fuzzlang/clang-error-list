
namespace cwg647 { // cwg647: 3.1
  struct NonLiteral { NonLiteral() {} }; // #cwg647-NonLiteral

  struct C {
    constexpr C(NonLiteral);
    constexpr C(NonLiteral, int) {}
    constexpr C() try {} catch (...) {}
    // expected-error@-1 {{function try block in constexpr constructor is a C++20 extension}}
  };
}
