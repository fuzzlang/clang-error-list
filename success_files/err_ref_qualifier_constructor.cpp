
class X {
public:
    X() &; // expected-error{{ref-qualifier '&' is not allowed on a constructor}}
};
