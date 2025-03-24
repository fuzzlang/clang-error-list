
void ALIGN_BUILTIN(void *ptr, size_t alignment);

int main() {
    void *ptr = NULL;
    (void)ALIGN_BUILTIN(ptr, 3); // expected-error {{requested alignment is not a power of 2}}
    return 0;
}
