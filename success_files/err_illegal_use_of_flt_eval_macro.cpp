
extern "C" int printf(const char *, ...);

void apply_pragma() {
    // expected-note@+1{{#pragma entered here}}
    #pragma clang fp eval_method(double)
    // expected-error@+1{{'__FLT_EVAL_METHOD__' cannot be expanded inside a scope containing '#pragma clang fp eval_method'}}
    printf("FP: %d\n", __FLT_EVAL_METHOD__);
}
