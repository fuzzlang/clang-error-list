
void failure_too_many_parameters(void *dst, const void *src, size_t count, size_t nothing) 
    __attribute__((diagnose_as_builtin(__builtin_memcpy, 1, 2, 3, 4))) 
{
}
