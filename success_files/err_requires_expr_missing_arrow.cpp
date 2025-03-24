
bool r27 = requires { { 0 } noexcept; }; // expected-error@-1 {{expected expression}}

bool r28 = requires { { 0 } noexcept noexcept; }; // expected-error@-1 {{expected expression}}
