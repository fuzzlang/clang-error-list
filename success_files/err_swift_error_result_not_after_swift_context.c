
#define ERROR_RESULT __attribute__((swift_error_result))
#define CONTEXT __attribute__((swift_context))

void error_result_nonswift(ERROR_RESULT void **error); // expected-error {{'swift_error_result' parameter can only be used with swiftcall calling convention}} expected-error{{'swift_error_result' parameter must follow 'swift_context' parameter}}
