
void bar() __attribute__((cmse_nonsecure_entry)); // expected-error{{function type with 'cmse_nonsecure_entry' attribute must have C linkage}}
