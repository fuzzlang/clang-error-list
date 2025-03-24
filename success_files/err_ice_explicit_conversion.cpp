
struct Explicit {
  constexpr Explicit() {}
  constexpr explicit operator int() const { return 4; } // expected-note {{here}}
} constexpr expl;

auto new3 = new int[1][expl]; // expected-error {{explicit conversion}}
