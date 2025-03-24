
void test() {
    #pragma omp for schedule(monotonic, nonmonotonic: auto) // expected-error {{modifier 'nonmonotonic' cannot be used along with modifier 'monotonic'}}
    for (int i = 0; i < 10; ++i) {
        // loop body
    }
}
