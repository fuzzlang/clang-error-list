
#define SWIFTCALL __attribute__((swiftcall))
#define INDIRECT_RESULT __attribute__((swift_indirect_result))

void indirect_result_bad_position(int first, INDIRECT_RESULT void *out) SWIFTCALL; // expected-error {{'swift_indirect_result' parameters must be first parameters of function}}
