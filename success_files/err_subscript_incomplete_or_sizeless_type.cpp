
typedef __SVInt8_t svint8_t;

svint8_t *global_int8_ptr;

void func() {
    svint8_t local_int8;
    global_int8_ptr[0] = local_int8;       // expected-error {{subscript of pointer to sizeless type 'svint8_t'}}
}
