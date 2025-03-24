
namespace cwg272 {
  struct X {
    void f() {
      this->~X(); // expected-error@-1 {{extra qualification on member '~X'}}
      X::~X();    // expected-error@-2 {{extra qualification on member '~X'}}
      ~X();       // expected-error@-3 {{extra qualification on member '~X'}}
    }
  };
}
