
#pragma clang attribute push (__attribute__((objc_bridge_related(1))), apply_to=function) // expected-error {{expected a related Objective-C class name, e.g., 'NSColor'}}
void myFunction() {}
#pragma clang attribute pop
