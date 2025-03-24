
void example_function() {
    int x;

#pragma omp depobj(x) destroy
    {
        // Some code here
    }
}
