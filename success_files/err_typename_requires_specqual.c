
typedef char i8;
struct S {
    vector bool i8;                    // expected-error {{requires a specifier or qualifier}}
};
