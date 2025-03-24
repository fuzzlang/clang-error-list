
#pragma clang attribute push (__attribute__((annotate)), apply_to=function foo) // expected-error {{extra tokens after attribute in a '#pragma clang attribute push'}}
