
#pragma clang attribute push(__attribute__((annotate("test"))), apply_to = any( unknown_rule )) // expected-error {{unknown attribute subject rule 'unknown_rule'}}
#pragma clang attribute pop
