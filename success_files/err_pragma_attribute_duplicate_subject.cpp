
#pragma clang attribute push(__attribute__((annotate("test"))), apply_to = any(function, function)) // expected-error {{duplicate attribute subject matcher 'function'}}

void myFunction() {}
