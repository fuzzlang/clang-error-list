
#define STRING2(x) #x
#define STRING(x) STRING2(x)

void func() {
#pragma GCC error(":O I'm a message! " STRING(__LINE__)) // expected-error {{:O I'm a message! 24}}
}
