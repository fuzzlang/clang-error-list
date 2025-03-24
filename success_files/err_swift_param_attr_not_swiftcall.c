
#define INDIRECT_RESULT __attribute__((swift_indirect_result))

void indirect_result_nonswift(INDIRECT_RESULT void *out); // expected-error {{'swift_indirect_result' parameter can only be used with swiftcall or swiftasynccall calling convention}}
