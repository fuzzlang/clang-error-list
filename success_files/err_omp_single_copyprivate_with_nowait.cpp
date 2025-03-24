
int main() {
    int i;

    #pragma omp single copyprivate(i) nowait // expected-error {{the 'copyprivate' clause must not be used with the 'nowait' clause}} expected-note {{'nowait' clause is here}}
    {
        i = 1;
    }

    return 0;
}
