
struct S {
    float : 12;     // expected-error {{anonymous bit-field has non-integral type 'float'}}
};
