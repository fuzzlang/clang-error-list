
class C {
    struct S; // expected-note {{previously declared 'private' here}}
public:
    struct S {}; // expected-error {{'S' redeclared with 'public' access}}
};
