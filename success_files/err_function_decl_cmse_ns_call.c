
void foo(callback_ns_1t nsfptr) __attribute__((cmse_nonsecure_call)); // expected-error{{functions may not be declared with 'cmse_nonsecure_call' attribute}}

void bar() {
    // Your additional function code here
}
