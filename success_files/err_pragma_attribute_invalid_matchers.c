
// expected-error@-1 {{negated attribute subject matcher sub-rule 'variable(unless(is_parameter))' contradicts sub-rule 'variable(is_global)'}}
// We have just one error, don't error on 'variable(is_global)'

// Ensure that we've recovered from the error:
int testRecoverNegatedContradiction = 0;
// CHECK-LABEL: VarDecl{{.*}} testRecoverNegatedContradiction
// CHECK-NEXT: IntegerLiteral
// CHECK-NEXT: AnnotateAttr{{.*}} "negatedSubRuleContradictions2"

void testRecoverNegatedContradictionFunc(void);
// CHECK-LABEL: FunctionDecl{{.*}} testRecoverNegatedContradictionFunc
// CHECK-NEXT: AnnotateAttr{{.*}} "negatedSubRuleContradictions2"

#pragma clang attribute pop

// Verify the strict subject set verification.

#pragma clang attribute push (__attribute__((abi_tag("a"))), apply_to = any(function))

int testRecoverStrictnessVar = 0;
// CHECK-LABEL: VarDecl{{.*}} testRecoverStrictnessVar
// CHECK-NEXT: IntegerLiteral
// CHECK-NOT: AbiTagAttr

void testRecoverStrictnessFunc(void);
// CHECK-LABEL: FunctionDecl{{.*}} testRecoverStrictnessFunc
// CHECK-NEXT: AbiTagAttr

struct testRecoverStrictnessStruct { };
// CHECK-LABEL: RecordDecl{{.*}} testRecoverStrictnessStruct
// CHECK-NOT: AbiTagAttr

#pragma clang attribute pop

#pragma clang attribute push (__attribute__((abi_tag("a"))), apply_to = any(function, record(unless(is_union)), variable, enum)) 
