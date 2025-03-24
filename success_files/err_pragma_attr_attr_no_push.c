
void func() {
#pragma clang attribute (__attribute__((annotate)), apply_to = function) // expected-error{{'#pragma clang attribute' attribute with no matching '#pragma clang attribute push}}
}
