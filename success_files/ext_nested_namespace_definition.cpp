
// expected-error@-1 {{member 'X' found in multiple base classes of different types}}
//   expected-note@#cwg306-X {{member type 'cwg306::X' found}}
//   expected-note@#cwg306-typedef-X {{member type 'const cwg306::X' found}}
}

namespace cwg308 { // cwg308: 3.7
  struct A {};
  struct B : A {};
  struct C : A {};
  struct D : B, C {};
  void f() {
    try {
      throw D();
    } catch (const A&) { // #cwg308-catch-A
      // unreachable
    } catch (const B&) {
      // expected-warning@-1 {{exception of type 'const B &' will be caught by earlier handler}}
      //   expected-note@#cwg308-catch-A {{for type 'const A &'}}
    }
  }
}

namespace cwg311 { // cwg311: 3.0
  namespace X { namespace Y {} }
  namespace X::Y {}
}
