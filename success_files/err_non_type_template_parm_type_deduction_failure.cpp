
template<auto (*f)()> struct X { /* ... */ };

X<nullptr> x; // expected-error {{incompatible initializer}}
