
// expected-error@+1{{no macro named 'foo'}}
#pragma clang restrict_expansion(foo)

void test() {}
