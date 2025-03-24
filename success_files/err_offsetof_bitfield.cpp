
struct has_bitfields {
    int i : 7;
    int j : 12; // expected-note{{bit-field is declared here}}
};

int test3 = __builtin_offsetof(struct has_bitfields, j); // expected-error{{cannot compute offset of bit-field 'j'}}
