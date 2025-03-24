
namespace cwg484 {
  struct C;
  typedef C CT; // expected-note {{'CT' declared here}}
  struct CT {}; // expected-error {{definition of type 'CT' conflicts with typedef of the same name}}
}

