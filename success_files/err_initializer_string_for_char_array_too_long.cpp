
char16_t o = '👽'; // expected-error {{character too large for enclosing character literal type}}

char16_t p[2] = u"\U0000FFFF"; // Here it is valid as it fits in char16_t
char16_t q[2] = u"\U00010000"; // expected-error {{character too large for enclosing character literal type}}
