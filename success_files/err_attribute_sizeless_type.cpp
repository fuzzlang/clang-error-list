
typedef __SVInt8_t svint8_t;

void func(int sel) {
  svint8_t __attribute__((aligned)) aligned_int8_1;    // expected-error {{'aligned' attribute cannot be applied to sizeless type 'svint8_t'}}
}
