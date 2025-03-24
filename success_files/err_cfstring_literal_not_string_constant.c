
#define CFSTR __builtin___CFStringMakeConstantString

void test7(void) {
    const void *X;
    X = CFSTR(242); // expected-error {{CFString literal is not a string constant}} expected-error {{incompatible integer to pointer conversion}}
}
