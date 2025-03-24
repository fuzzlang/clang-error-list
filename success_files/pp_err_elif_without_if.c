
#ifdef FOO
#endif

#elifdef FOO /* expected-error {{#elifdef without #if}} */

