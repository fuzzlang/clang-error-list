
// RUN: %clang_cc1 -fsyntax-only -Wno-pragma-clang-attribute -verify %s
// RUN: not %clang_cc1 -ast-dump -ast-dump-filter test %s | FileCheck %s

// Check for contradictions in rules for attribute without a strict subject set:

#pragma clang attribute push (__attribute__((annotate("subRuleContradictions"))), apply_to = any(variable, variable(is_parameter), variable(is_global), function(is_member), function(is_member))) // should produce iserr_pragma_attribute_matcher_subrule_contradicts_rule
int global_var;

void func(int param) {
    // Function body
}
