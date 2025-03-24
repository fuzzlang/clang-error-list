
#define SWIFTCALL __attribute__((swiftcall))

void unprototyped() SWIFTCALL; // expected-error {{function with no prototype cannot use the swiftcall calling convention}}
