
void example_function() {
    int a = 0;
    
    #pragma omp atomic fail(seq_cst)
    a++; // This will trigger the expected error.
}
