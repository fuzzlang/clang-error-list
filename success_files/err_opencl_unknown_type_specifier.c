
kernel void example_kernel() {
    constant int L1 = 42; // expected-error {{variables in the constant address space can only be declared in the outermost scope of a kernel function}}
    
    {
        auto int L3 = 7; // This line does not produce an error, but is included for context.
    }
}
