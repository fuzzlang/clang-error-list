
static int OvlFoo(void *const p __attribute__((pass_object_size(1))));
static int OvlFoo(void *const p __attribute__((pass_object_size(2)))); // expected-error{{conflicting pass_object_size attributes on parameters}} expected-note@-1{{previous declaration is here}}
