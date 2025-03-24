
void test_function() {
    half *p; // Declare a pointer to type 'half'
    *p = 0;  // expected-error{{assigning directly to pointer to type 'half' requires cl_khr_fp16. Use vector data store builtin functions instead}}
}
