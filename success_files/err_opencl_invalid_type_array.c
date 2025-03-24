
__kernel void example_kernel(__global float *output) {
    sampler_t sa[] = {argsmp, glb_smp}; // expected-error {{array of 'sampler_t' type is invalid in OpenCL}}
}
