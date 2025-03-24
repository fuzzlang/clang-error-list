
typedef __SVInt8_t svint8_t;

svint8_t global_int8;          // expected-error {{non-local variable with sizeless type 'svint8_t'}}
