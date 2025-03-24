
namespace isext_enum_base_in_type_specifier {
  struct A {
    enum E : int { 1 }; // expected-error {{expected identifier}} (not bit-field)
  };
  auto *p1 = new enum E : int; // expected-error {{expected identifier}} (not bit-field)
}
