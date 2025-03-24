
int main() {
    int a = 0;

    #pragma omp target update // expected-error {{expected at least one 'to' clause or 'from' clause specified to '#pragma omp target update'}}
    
    return 0;
}
