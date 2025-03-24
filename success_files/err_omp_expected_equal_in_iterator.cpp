
void example() {
    int argc;

    #pragma omp task depend(iterator(unsigned argc:  // expected-error {{expected ')'}} 
    {
        // Task implementation here
    }
}
