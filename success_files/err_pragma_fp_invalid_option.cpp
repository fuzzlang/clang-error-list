
void test() {
    /* expected-error@+1 {{missing option; expected 'contract', 'reassociate', 'reciprocal', or 'exceptions'}} */
    #pragma clang fp
}
