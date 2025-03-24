
void some_function() {
    int *ptr;
    (void)ALIGN_BUILTIN(ptr, 0); // expected-error {{requested alignment must be 1 or greater}}
}
