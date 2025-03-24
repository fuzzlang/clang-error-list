
struct X {
  static const double x = 0.0; // expected-error@20 {{in-class initializer for static data member of type 'const double' requires 'constexpr' specifier}}
  // expected-note@20 {{add 'constexpr'}}
};
