
namespace AnonymousMember {
  struct Struct {
    struct { // expected-note {{declared here}}
      int i;
    };
  };

  void test() {
    auto [a1] = Struct(); // expected-error {{cannot decompose class type 'Struct' because it has an anonymous struct member}}
  }
}
