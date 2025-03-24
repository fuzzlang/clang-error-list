
typedef struct {int i, j, k;} invalid_4 __attribute__((mode(SI))); // expected-error{{mode attribute only supported for integer and floating-point types}}
