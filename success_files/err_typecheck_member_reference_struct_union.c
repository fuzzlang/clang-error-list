
void test() {
    void *ptr = NULL;
    ptr->a; /* expected-error {{member reference base type 'void' is not a structure or union}} */
}
