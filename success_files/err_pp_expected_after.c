
// expected-error@+1 {{missing ')' after 'abc'}}
#if __is_identifier(abc xyz) // expected-note {{to match this '('}}
#endif
