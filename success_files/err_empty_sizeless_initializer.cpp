
typedef __SVInt8_t svint8_t;

void func(int sel) {
  svint8_t empty_brace_init_int8 = {}; // expected-error {{initializer for sizeless type 'svint8_t' (aka '__SVInt8_t') cannot be empty}}
}
