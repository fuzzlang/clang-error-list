
namespace lambdas {
  void f() {
    int n;
    auto [a] =  // expected-error {{cannot decompose lambda closure type}}
        [n] {}; // expected-note {{lambda expression}}
  }
}
