
struct bitfield {
    int field : 1;
};

void test() {
    __auto_type j = (struct bitfield){1}.field; // expected-error {{cannot pass bit-field as __auto_type initializer in C}}
}
