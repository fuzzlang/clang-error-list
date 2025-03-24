
struct A {};

void test_errors() {
    (void)__can_pass_in_regs(const A); // expected-error {{not an unqualified class type}}
}
