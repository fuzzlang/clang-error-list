
namespace Thirteen {
enum class Bob { a };
class Foo {
  using enum Bob; // expected-note{{previous using-enum}}
  using enum Bob; // expected-error{{redeclaration of using-enum}}
};
}
