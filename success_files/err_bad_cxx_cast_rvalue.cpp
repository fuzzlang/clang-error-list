
struct A {};
typedef char c;
typedef c *cp;
typedef cp *cpp;
typedef cpp *cppp;
typedef cppp &cpppr;

void bad_const_cast_test(char const *volatile *const volatile *var) {
    char **var2 = const_cast<char**>(var); // expected-error {{const_cast from 'const char *volatile *const volatile *' to 'char **' is not allowed}}
    char ***&var4 = const_cast<cpppr>(&var2); // expected-error {{const_cast from rvalue to reference type 'cpppr'}}
}
