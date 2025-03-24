
void usages() {
    __attribute__((opencl_global)) int *GLOB;
    __attribute__((opencl_private)) int *PRIV;

    GLOB = (__attribute__((opencl_global)) int *)PRIV; // expected-error {{C-style cast from '__private int *' to '__global int *' converts between mismatching address spaces}}
}
