
namespace constinit_mismatch {
  int b = 123; // expected-note {{add the 'constinit' specifier}}
  extern constinit int b; // expected-error {{'constinit' specifier added after initialization of variable}}
}
