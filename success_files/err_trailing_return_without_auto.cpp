
// expected-error@-1 {{redefinition of 'operator+<0>'}}
// expected-note@#cwg679-def {{previous definition is here}}

namespace cwg681 { // cwg681: partial
  auto *a() -> int; // Function declaration
}

auto operator+(int x, int y) -> int; // Re-declaring operator+
auto operator+(int x, int y) -> int { return x + y; } // Definition of operator+
