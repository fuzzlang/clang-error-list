
int test17(int t0) {
    int r0, r1;
    __asm ("addl %2, %2\\n\\t"
           "movl $123, %0"
           : "=a" (r0),
             "=&r" (r1)
           : "1" (t0),   // expected-note {{constraint '1' is already present here}}
             "1" (t0));  // expected-error {{more than one input constraint matches the same output '1'}}
    return r0 + r1;
}
