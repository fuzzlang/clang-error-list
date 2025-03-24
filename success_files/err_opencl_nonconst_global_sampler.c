
global sampler_t glb_smp3 = CLK_ADDRESS_CLAMP_TO_EDGE | CLK_NORMALIZED_COORDS_TRUE | CLK_FILTER_NEAREST; // expected-error{{sampler type cannot be used with the __local and __global address space qualifiers}} expected-error {{global sampler requires a const or constant address space qualifier}}
