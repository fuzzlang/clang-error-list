
int a7() __attribute__((weakref("f1"))); // expected-error {{weakref declaration must have internal linkage}}
