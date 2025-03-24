
namespace y {
  struct a { };
  typedef int b;
}

y:a a2;  // expected-error {{unexpected ':' in nested name specifier}}
