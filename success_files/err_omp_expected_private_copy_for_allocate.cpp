
int main() {
    int d;
    #pragma omp parallel allocate(d) // expected-error {{the referenced item is not found in any private clause on the same directive}}
    {
    }
    return 0;
}
