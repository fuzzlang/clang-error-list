
extern constexpr int m; // expected-error {{constexpr variable declaration must be a definition}}

constexpr int n = 10; // Definition of another constexpr variable
