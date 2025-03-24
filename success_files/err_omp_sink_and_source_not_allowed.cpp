
void exampleFunction() {
    #pragma omp ordered depend(sink : i-0, j+sizeof(int)) depend(source) // expected-error {{'depend(source)' clause cannot be mixed with 'depend(sink:vec)' clauses}}
    {
        // Some computation
    }
}
