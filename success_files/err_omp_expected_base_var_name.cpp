
void example() {
    int qa[10];
    
    // Assuming get() is defined elsewhere and returns a pointer or array
    int* get();

    #pragma omp for reduction(+ : qa[1], get()[0]) // expected-error {{expected variable name as a base of the array subscript}}
    for (int i = 0; i < 10; ++i) {
        qa[i] = i;
    }
}
