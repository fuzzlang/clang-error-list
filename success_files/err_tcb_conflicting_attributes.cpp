
__attribute__((enforce_tcb("x")))
__attribute__((enforce_tcb_leaf("x"))) // expected-error{{attributes 'enforce_tcb_leaf("x")' and 'enforce_tcb("x")' are mutually exclusive}}
void myFunction() {
    // Function body
}
