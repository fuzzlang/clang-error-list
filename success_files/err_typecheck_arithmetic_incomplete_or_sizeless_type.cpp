
typedef __SVInt8_t svint8_t;

void dump(const volatile void *);

void func(int sel) {
    svint8_t local_int8;
    dump(&local_int8 + 1); // expected-error {{arithmetic on a pointer to sizeless type}}
}
