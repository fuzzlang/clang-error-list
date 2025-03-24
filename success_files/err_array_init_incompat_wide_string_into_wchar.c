
typedef int wchar_t;
typedef unsigned short char16_t;
typedef unsigned int char32_t;

void f(void) {
    wchar_t b3[] = u"a"; // expected-error{{initializing wide char array with incompatible wide string literal}}
}
