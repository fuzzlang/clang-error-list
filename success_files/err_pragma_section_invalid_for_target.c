
void test_function() {
#pragma clang section bss = "" data = "" rodata = "" text = "badname"  // expected-error {{argument to #pragma section is not valid for this target: mach-o section specifier requires a segment and section separated by a comma}}
}
