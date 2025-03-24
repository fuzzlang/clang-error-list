
namespace test6 {
struct C {
  template <typename> friend struct A; // expected-note {{'A' declared here}};
};

struct B {
  struct A *p; // expected-error {{implicit declaration introduced by elaborated type conflicts with a template of the same name}};
};
}
