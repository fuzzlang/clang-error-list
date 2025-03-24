
namespace DtorErrors {
  struct C; // expected-note {{forward decl}}
  ~C::C() {} // expected-error {{incomplete}} expected-error {{'~' in destructor name should be after nested name specifier}}
}
