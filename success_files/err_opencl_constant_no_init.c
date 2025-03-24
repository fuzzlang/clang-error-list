
constant sampler_t glb_smp2; // expected-error{{variable in constant address space must be initialized}}

__kernel void my_kernel() {
    // Kernel code here
}
