
void testFunction() {
#pragma float_control(push) // expected-error {{can only appear at file or namespace scope or within a language linkage specification}}
    int a = 0;
}
