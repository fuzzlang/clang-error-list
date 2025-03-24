
struct S {
    int e : 0;  // expected-error {{bit-field 'e' has zero width}}
};
