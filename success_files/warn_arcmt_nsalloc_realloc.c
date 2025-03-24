
#define CF_AUTOMATED_REFCOUNT_UNAVAILABLE __attribute__((unavailable("not available in automatic reference counting mode")))
typedef unsigned NSUInteger;
typedef const void * CFTypeRef;
CFTypeRef CFMakeCollectable(CFTypeRef cf) CF_AUTOMATED_REFCOUNT_UNAVAILABLE; // expected-note {{unavailable}}
void *__strong NSAllocateCollectable(NSUInteger size, NSUInteger options);

void test1(CFTypeRef *cft) {
    NSAllocateCollectable(100, 0); // expected-error {{call returns pointer to GC managed memory; it will become unmanaged in ARC}}
}
