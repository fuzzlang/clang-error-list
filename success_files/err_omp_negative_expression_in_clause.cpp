
void example_function(int argc) {
    // expected-error@+1 2 {{integral constant expression}} expected-note@+1 0+{{constant expression}}
    #pragma omp for collapse (foobool(argc)), collapse (true), collapse (-5)
    for (int i = 0; i < 10; ++i) {
        // loop body
    }
}
