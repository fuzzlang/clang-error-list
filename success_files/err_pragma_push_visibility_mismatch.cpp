
namespace test2 __attribute__((visibility("hidden"))) { // expected-note{{surrounding namespace with visibility attribute starts here}}
#pragma GCC visibility push(protected) // expected-error{{#pragma visibility push with no matching #pragma visibility pop}}
} // expected-note{{surrounding namespace with visibility attribute ends here}}
