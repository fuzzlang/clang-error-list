
void bad(sampler_t*); // expected-error{{pointer to type 'sampler_t' is invalid in OpenCL}}

__kernel void kernel_func() {
    sampler_t* s; // expected-error{{pointer to type 'sampler_t' is invalid in OpenCL}}
    bad(s);
}
