
#pragma clang attribute push(__attribute__((annotate("test"))), ) // expected-error {{expected attribute subject set specifier 'apply_to'}}

void function();
