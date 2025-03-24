
#pragma clang attribute push (__attribute__((annotate("func"))), apply_to = function)
// expected-error {{unterminated '#pragma clang attribute push' at end of file}}
