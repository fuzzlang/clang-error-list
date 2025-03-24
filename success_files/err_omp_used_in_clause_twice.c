
void foo() {
    int x[10];
    int z[10];
    
    #pragma omp distribute simd aligned(x) aligned(z, x)
    {
        // Your code here
    }
}
