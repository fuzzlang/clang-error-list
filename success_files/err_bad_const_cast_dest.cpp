
struct A {};

typedef char c;
typedef c *cp;
typedef cp *cpp;
typedef cpp *cppp;
typedef cppp &cpppr;

short *bad_const_cast_test(char const *volatile *const volatile *var) {
    char **var2 = const_cast<char**>(var); // expected-error {{const_cast from 'const char *volatile *const volatile *' to 'char **' is not allowed}}
    char v = const_cast<char>(**var2); // expected-error {{const_cast to 'char', which is not a reference, pointer-to-object, or pointer-to-data-member}}
}
