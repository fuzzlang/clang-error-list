
// expected-error@+1 {{nested parentheses not permitted in '__is_identifier'}}
#if __is_identifier((abc))
#endif
