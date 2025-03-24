
void test() {
    #pragma omp for ordered
    for (int i = 0; i < 10; ++i) {
        #pragma omp ordered
        {
            // Some code
        }
        #pragma omp ordered // expected-error {{exactly one 'ordered' directive must appear in the loop body of an enclosing directive}}
        {
            // Some code
        }
    }
}
