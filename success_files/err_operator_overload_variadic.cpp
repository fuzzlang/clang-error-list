
struct X {};

X operator/(X, X, ...); // expected-error{{overloaded 'operator/' cannot be variadic}}
