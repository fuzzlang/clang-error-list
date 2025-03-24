
void f3(void) __attribute__((availability(ios, deprecated=10.4.7, introduced=10, obsoleted=10.6, introduced=10.2))); // expected-error{{redundant 'introduced' availability change; only the last specified change will be used}}
