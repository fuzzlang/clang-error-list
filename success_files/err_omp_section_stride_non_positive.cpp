
int main() {
    int iarr[5][5];
    #pragma omp target update to(iarr[0:][1:2:-1]) // expected-error {{expected at least one 'to' clause or 'from' clause specified to '#pragma omp target update'}}
    {}
    return 0;
}
