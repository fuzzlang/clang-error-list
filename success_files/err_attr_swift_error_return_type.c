
typedef struct __attribute__((__objc_bridge__(NSError))) __CFError *CFErrorRef;

extern void *o0(CFErrorRef *) __attribute__((__swift_error__(none)));
extern void *o1(CFErrorRef *) __attribute__((__swift_error__(nonnull_error)));
extern void *o2(CFErrorRef *) __attribute__((__swift_error__(null_result)));
extern void *o3(CFErrorRef *) __attribute__((__swift_error__(nonzero_result))); // expected-error@-1 {{'__swift_error__' attribute with 'nonzero_result' convention can only be applied to a function returning an integral type}}
extern void *o4(CFErrorRef *) __attribute__((__swift_error__(zero_result)));
