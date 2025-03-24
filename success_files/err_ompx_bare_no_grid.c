
int main() {
    #pragma omp target teams ompx_bare
    {
        // Some code here
    }
    return 0;
}
