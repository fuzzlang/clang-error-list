
namespace I {
    namespace A1 { int i; }
    namespace A2 = A1;
    namespace A3::extra::specifiers = A2;  // expected-error {{alias must be a single identifier}}
}
