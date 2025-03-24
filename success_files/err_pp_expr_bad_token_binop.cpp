
// expected-error@+3 {{token is not a valid binary operator in a preprocessor subexpression}}
#endif
// Invalid because 'and' is used incorrectly
#if defined foo and bar
#endif
