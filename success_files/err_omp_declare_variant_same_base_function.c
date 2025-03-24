
// expected-error@+1 {{variant in '#pragma omp declare variant' is the same as the base function}}
#pragma omp declare variant (self) match(construct={dispatch}, device={arch(arm)})
void self(int n) {
    // Function implementation
}
