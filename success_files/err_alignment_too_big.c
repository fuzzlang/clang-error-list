
struct Aggregate {
    int i;
    int j;
};

void test_invalid_alignment_values(char *ptr, long *longptr, size_t align) {
    __UINT8_TYPE__ c = ' ';
    
    (void)ALIGN_BUILTIN(c, 128);        // this is fine
    (void)ALIGN_BUILTIN(c, 256);        // expected-error {{requested alignment must be 128 or smaller}}
}
