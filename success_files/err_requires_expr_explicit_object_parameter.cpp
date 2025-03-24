
auto x0 = requires (this int) { true; }; // expected-error {{a requires expression cannot have an explicit object parameter}}
