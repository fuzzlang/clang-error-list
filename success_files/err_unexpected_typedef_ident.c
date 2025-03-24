
typedef int atype;

void test3(x,            /* expected-warning {{a function definition without a prototype is deprecated in all versions of C and is not supported in C23}} */
           atype         /* expected-error {{unexpected type name 'atype': expected identifier}} */
          ) int x, atype; {}
