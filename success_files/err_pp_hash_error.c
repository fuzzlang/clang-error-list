
void example() {
    #error should not be ignored
    #pragma omp parallel
    {
        // Some code here
    }
}
