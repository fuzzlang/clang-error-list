
void foo();

int main() {
    #pragma omp parallel
    {
        #pragma omp for
        foo(); // expected-error {{expected 2 for loops after '#pragma omp for'}}
    }
    return 0;
}
