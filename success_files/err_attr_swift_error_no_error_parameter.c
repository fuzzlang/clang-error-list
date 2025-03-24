
typedef int NSError;

int functionWithErrorParam(NSError **error) __attribute__((__swift_error__(nonnull_error)));
// expected-error@-1 {{'__swift_error__' attribute can only be applied to a method with an error parameter}}
