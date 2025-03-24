
enum { E = [](auto i) { return i; }(3) }; // expected-error{{inside of a constant expression}}
