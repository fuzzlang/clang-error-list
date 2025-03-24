
struct X {};
struct S {};
struct E {}; // E is not a base of Z

struct Z : X, S {
    Z() : X(), S(), E() {} // expected-error {{type 'E' is not a direct or virtual base of 'Z'}}
};
