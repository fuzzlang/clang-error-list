
void *fail13(int a) __attribute__((alloc_size(1U << 31))); //expected-error{{integer constant expression evaluates to value 2147483648 that cannot be represented in a 32-bit signed integer type}}

void test_function() {
    // This function is just to ensure the attribute declaration is placed correctly
}
