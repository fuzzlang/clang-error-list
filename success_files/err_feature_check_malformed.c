
// expected-error@+1 {{builtin feature check macro requires a parenthesized identifier}}
#if __has_feature('x')
#endif
