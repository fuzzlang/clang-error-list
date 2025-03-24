
bool r12 = requires (int x = 10) { requires true; }; // expected-error@-2 {{expected ')'}} // expected-note@-3 {{to match this '('}}
