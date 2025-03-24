
// RUN: %clang_cc1 %s -Eonly -verify

/* expected-warning@+1 {{use of a '#elifdef' directive is a C23 extension}} */
#elifdef FOO /* expected-error {{#elifdef without #if}} */
#endif       /* expected-error {{#endif without #if}} */
