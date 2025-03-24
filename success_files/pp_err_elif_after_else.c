
/* expected-error@+4 {{#elifdef after #else}} */
/* expected-warning@+3 {{use of a '#elifdef' directive is a C23 extension}} */
#ifdef FOO
#else
#elifdef BAR
#endif
