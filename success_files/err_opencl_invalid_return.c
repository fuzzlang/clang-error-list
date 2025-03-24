
sampler_t bad(void); // expected-error{{declaring function return value of type 'sampler_t' is not allowed}}

void func() {
    // OpenCL code block
    #pragma OPENCL EXTENSION cl_khr_fp64 : enable
    {
        // body of the OpenCL kernel
    }
}
