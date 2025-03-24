
#pragma GCC poison BLARG
void test_poisoned_identifier() {
    BLARG; // expected-error {{attempt to use a poisoned identifier}}
}
