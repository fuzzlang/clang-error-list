
namespace PR42108 {
  struct R {};
  struct S { constexpr S() {} constexpr S(R) {} };
  struct T { constexpr operator S() { return {}; } };
  template <const S &> struct A {};
  void f() {
    A<R{}>(); // expected-error {{would bind reference to a temporary}}
  }
}
