
struct X {};

X operator*(X, X = X()); // expected-error{{parameter of overloaded 'operator*' cannot have a default argument}}
