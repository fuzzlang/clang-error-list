
void bar(int);

void foo() {
    int i;
    int a[10], b[10];

    [[clang::code_align(64)]]
    [[clang::code_align(8)]] // expected-note{{previous attribute is here}}
    [[clang::code_align(64)]] // expected-error{{conflicting loop attribute 'code_align'}}
    for (i = 0; i < 10; ++i) {
        a[i] = b[i] = 0;
    }
}
