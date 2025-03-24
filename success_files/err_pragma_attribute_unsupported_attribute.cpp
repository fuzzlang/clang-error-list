
#pragma clang attribute push (__attribute__((used)), apply_to=function) // expected-error {{attribute 'used' is not supported by '#pragma clang attribute'}}
void myFunction() {
    // Function implementation
}
#pragma clang attribute pop
