
struct B1 {
    B1(int) {}
};

struct I1 : B1 { 
    using B1::B1; // expected-note {{previous using declaration}}
    using B1::B1; // expected-error {{redeclaration of using decl}}
};

struct D1 : I1 {
    using B1::B1; // expected-error {{'B1' is not a direct base of 'D1', cannot inherit constructors}}
};
