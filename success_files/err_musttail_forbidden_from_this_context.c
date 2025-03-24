
void TestObjcBlock(void) {
    void (^x)(void) = ^(void) {
        __attribute__((musttail)) return TestObjcBlock(); // expected-error{{'musttail' attribute cannot be used from a block}}
    };
    x();
}
