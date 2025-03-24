
#define PROTECTED __attribute__((visibility("protected")))

__attribute__((dllimport)) PROTECTED void imported_protected(); // expected-error {{non-default visibility cannot be applied to 'dllimport' declaration}}

void foo() { imported_protected(); }
