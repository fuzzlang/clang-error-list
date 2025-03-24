
#if __cplusplus >= 201103L
// cwg1948: 3.5
// expected-error@-1 {{exception specification in declaration does not match previous declaration}}
void *operator new(__SIZE_TYPE__) noexcept { return nullptr; }
void *operator new(__SIZE_TYPE__ size) noexcept(false) { return nullptr; }
#endif
