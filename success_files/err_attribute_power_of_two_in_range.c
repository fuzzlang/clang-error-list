
void foo1(int A) {
    // expected-error@+1{{'code_align' attribute requires an integer argument which is a constant power of two between 1 and 4096 inclusive; provided argument was 0}}
    [[clang::code_align(0)]]
    for(int I = 0; I < 128; ++I) {
        bar(I);
    }
}
