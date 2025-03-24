
// expected-error@-2 {{redundant attribute subject matcher sub-rule 'variable(is_global)'; 'variable' already matches those declarations}}

// Ensure that we've recovered from the error:
int testRecoverSubRuleContradiction = 0;

#pragma clang attribute pop

#pragma clang attribute push (__attribute__((annotate("negatedSubRuleContradictions2"))), apply_to = any(variable(unless(is_parameter)), variable(is_thread_local), function, variable(is_global)))
