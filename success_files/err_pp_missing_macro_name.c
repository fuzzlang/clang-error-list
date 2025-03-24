
void example_function() {
#define INVALID defined(
#if INVALID // expected-error{{macro name missing}}
#endif
}
